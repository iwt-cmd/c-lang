#include "common.h"
#include "sockhead.h"

int main() {

    //Check Win socket initalized if applicable
    #if defined(_WIN32)
        WSDATA d;
        if (WSAStartup(MAKEWORD(2, 2), &d)) {
            fprintf(stderr, "Failed to initialize.\n");
            return 1;
        }
    #endif

    //Socket setup
    printf("Configuring local address...\n");
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    struct addrinfo *bind_address;
    getaddrinfo(0, "8080", &hints, &bind_address);
    
    //Create socket
    printf("Creating socket...\n");
    SOCKET socket_listen;
    socket_listen = socket(bind_address->ai_family, bind_address->ai_socktype, bind_address->ai_protocol);
    
    //Check if socket is setup and valid
    if(!ISVALIDSOCKET(socket_listen)){
        fprintf(stderr, "socket() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }

    //Bind socket (Bind returns 0 on success, non-0 on fail)
    printf("Binding socket to local address...\n");
    if (bind(socket_listen, bind_address->ai_addr, bind_address->ai_addrlen)) {
        fprintf(stderr, "bind() failed! (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    freeaddrinfo(bind_address);

    //Listening for connections (10 in queue max)
    printf("Listening (for those sweet connections)....\n");
    if (listen(socket_listen, 10) < 0) {
        fprintf(stderr, "listen() failed! (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    while (1) {
        //Waiting for connections
        printf("Waiting for connection...\n");
        struct sockaddr_storage client_address;
        socklen_t client_len = sizeof(client_address);
        SOCKET socket_client = accept(socket_listen, (struct sockaddr*) &client_address, &client_len);
        if (!ISVALIDSOCKET(socket_client)){
            fprintf(stderr, "access() failed! (%d)\n", GETSOCKETERRNO());
            return 1;
        }
        printf("Client is connected (sweet)...\n");
        char address_buffer[100];
        getnameinfo((struct sockaddr*)&client_address, client_len, address_buffer, sizeof(address_buffer), 0, 0, NI_NUMERICHOST);
        printf("%s\n", address_buffer);

        //Receive request
        printf("Receiving request (heads up)...\n");
        char request[1024];
        int bytes_received = recv(socket_client, request, 1024, 0);
        printf("Received %d bytes.\n", bytes_received);
        printf("%.*s", bytes_received, request);
        printf("\n");

        //...And send local time in HTTP response format
        printf("Sending response...\n");
        const char *response = 
            "HTTP/1.1 200 OK\r\n"
            "Connection: close\r\n"
            "Content-Type: text/plain\r\n\r\n"
            "Local Time is: ";
        int bytes_sent = send(socket_client, response, strlen(response), 0);
        printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(response));

        time_t timer;
        time(&timer);
        char *time_msg = ctime(&timer);
        bytes_sent = send(socket_client, time_msg, strlen(time_msg), 0);
        printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(time_msg));

        //Close connection & socket
        printf("Closing connection...\n");
        CLOSESOCKET(socket_client);
    }
    printf("Closing socket...\n");
    CLOSESOCKET(socket_listen);

    //Clean up Windows required
    #if defined(_WIN32)
        WSACleanup();
    #endif

    printf("Finished!\n");
    //printf("Local time: %s", ctime(&timer));

    return 0;
}