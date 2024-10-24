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

#define SERVER_PORT 8080  // Port for the server to listen on
#define BUFFER_SIZE 1024  // Size of the buffer for communication

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    char buffer[BUFFER_SIZE];
    const char *response = "Hello from Server!";

    // Create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Define server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);  // Convert to network byte order
    server_address.sin_addr.s_addr = INADDR_ANY;   // Accept connections from any IP address

    // Bind the socket to the port and address
    if (bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) == -1) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Server is listening on port %d...\n", SERVER_PORT);

    // Accept a client connection
    client_fd = accept(server_fd, (struct sockaddr*)&client_address, &client_address_len);
    if (client_fd == -1) {
        perror("accept");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Client connected!\n");

    // Receive a message from the client
    ssize_t bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv");
        close(client_fd);
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Message received from client: %s\n", buffer);

    // Send a response back to the client
    ssize_t bytes_sent = send(client_fd, response, strlen(response), 0);
    if (bytes_sent == -1) {
        perror("send");
        close(client_fd);
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Response sent to client: %s\n", response);

    // Close the client socket
    close(client_fd);
    // Close the server socket
    close(server_fd);

    return 0;
}
/*Server is listening on port 8080...
Client connected!
Message received from client: Hello from Client!
Response sent to client: Hello from Server!*/