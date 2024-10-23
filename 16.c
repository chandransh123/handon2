/*---
 Question 16
 : Write a program to send and receive data from parent to child vice versa. Use two way communication
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int parent_2_child[2];  // Pipe for parent to child communication
    int child_2_parent[2];  // Pipe for child to parent communication

    char parent_msg[] = "Hello from parent!";
    char child_msg[] = "Hello from child!";
    char buf[100];

    // Create both pipes
    if (pipe(parent_2_child) == -1 || pipe(child_2_parent) == -1) {
        perror("Pipe failed");
        return 1;
    }

    // Fork a new process
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(parent_2_child[0]);  // Close reading end of parent_2_child
        close(child_2_parent[1]);  // Close writing end of child_2_parent

        // Send message to child
        write(parent_2_child[1], parent_msg, strlen(parent_msg) + 1);
        close(parent_2_child[1]);  // Close writing end after sending

        // Wait for response from child
        read(child_2_parent[0], buf, sizeof(buf));
        printf("Parent received from child: %s\n", buf);
        close(child_2_parent[0]);  // Close reading end after receiving

        // Wait for child process to finish
        wait(NULL);
    } else {
        // Child process
        close(parent_2_child[1]);  // Close writing end of parent_2_child
        close(child_2_parent[0]);  // Close reading end of child_2_parent

        // Receive message from parent
        read(parent_2_child[0], buf, sizeof(buf));
        printf("Child received from parent: %s\n", buf);
        close(parent_2_child[0]);  // Close reading end after receiving

        // Send response to parent
        write(child_2_parent[1], child_msg, strlen(child_msg) + 1);
        close(child_2_parent[1]);  // Close writing end after sending
    }

    return 0;
}
/*Child received from parent: Hello from parent!
Parent received from child: Hello from child!*/