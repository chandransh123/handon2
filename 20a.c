/*---
Question 20a
 Write two programs so that both can communicate by FIFO - Use one way communication
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_FILE "/tmp/myfifo"

int main() {
    int fds;
    char writeBuffer[100];
    
    // Create the FIFO if it does not exist
    if (mkfifo(FIFO_FILE, 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    printf("Enter a message to send to the receiver: ");
    fgets(writeBuffer, sizeof(writeBuffer), stdin);

    // Open the FIFO for writing
    fds = open(FIFO_FILE, O_WRONLY);
    if (fds == -1) {
        perror("open");
        exit(1);
    }

    // Write the input to the FIFO
    write(fds, writeBuffer, strlen(writeBuffer) + 1);
    close(fds);
    
    printf("Message sent!\n");
    return 0;
}
// Enter a message to send to the receiver: hii atif here
// Message sent!
