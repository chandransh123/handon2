

// This is the server program
/*
Question 34a
:  Write a program to communicate between two machines using socket.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/

/*
    1. socket() -> create an endpoint for the communication
        sockfetfd = socket(AF_INET, SOCK_STREAM, 0);
    2. bind() -> bind a name to a socket
        bindStatus = bind(socketfd, &socketaddr, sizeof(socketfd));
    3. listen() -> listen for connections on a socket
        listenStatus = listen(socketfd, 2); // backlog -> 2
    4. accept() -> accept a connection on a socket
        connectionfd = accept(socketfd, &socketaddr, sizeof(socketaddr), 0);
    5. Start communicating -> `write` to and `read` from connectionfd
*/

// Server program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int serverfd, newsocket;
    struct sockaddr_in addres;
    int addrlen = sizeof(addres);
    char buffer[1024] = {0};
    const char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the addres structure
    addres.sin_family = AF_INET;
    addres.sin_addr.s_addr = INADDR_ANY;
    addres.sin_port = htons(PORT);

    // Binding the socket to the port
    if (bind(serverfd, (struct sockaddr *)&addres, sizeof(addres)) < 0) {
        perror("bind failed");
        close(serverfd);
        exit(EXIT_FAILURE);
    }

    // Listening for client connections
    if (listen(serverfd, 3) < 0) {
        perror("listen failed");
        close(serverfd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    // Accepting a connection from the client
    if ((newsocket = accept(serverfd, (struct sockaddr *)&addres, (socklen_t*)&addrlen)) < 0) {
        perror("accept failed");
        close(serverfd);
        exit(EXIT_FAILURE);
    }

    // Reading the message from the client
    read(newsocket, buffer, 1024);
    printf("Message from client: %s\n", buffer);

    // Sending a response to the client
    send(newsocket, hello, strlen(hello), 0);
    printf("Hello message sent to client\n");

    // Closing the connection
    close(newsocket);
    close(serverfd);

    return 0;
}
/*Server is listening on port 8080
Message from client: Hello from client
Hello message sent to client
*/