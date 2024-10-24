// Question : Write a program to communicate between two machines using socket.

// This is the client program

/*
    1. socket() -> create an endpoint for the communication
        sockfetfd = socket(AF_INET, SOCK_STREAM, 0);
    2. connect() -> initiate a connection to a socket
        connectionStatus = connect(socketfd, &socketaddr, sizeof(socketaddr));
    3. Start communicating -> `write` to and `read` from socketfd
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080  // Server port
#define BUFFER_SIZE 1024  // Size of the buffer for communication

int main() {
    int sock;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    const char *message = "Hello from Client!";
    
    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Define server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);  // Convert to network byte order
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");  // Server IP address (localhost for this example)

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("connect");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    if (send(sock, message, strlen(message), 0) == -1) {
        perror("send");
        close(sock);
        exit(EXIT_FAILURE);
    }
    printf("Message sent to the server: %s\n", message);

    // Receive a message from the server
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        close(sock);
        exit(EXIT_FAILURE);
    }
    printf("Message received from server: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}
/*
Message sent to the server: Hello from Client!
Message received from server: Hello from Server!��*/
