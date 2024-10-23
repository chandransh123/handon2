/*---
Question 20b
Write two programs so that both can communicate by FIFO - Use one way communication
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_FILE "/tmp/myfifo"

int main() {
    int fds;
    char readBuffer[100];

    // Open the FIFO for reading
    fds = open(FIFO_FILE, O_RDONLY);
    if (fds== -1) {
        perror("open");
        exit(1);
    }

    // Read from the FIFO
    read(fds, readBuffer, sizeof(readBuffer));
    printf("Received message: %s\n", readBuffer);
    
    close(fds);
    return 0;
}
// Received message: hii atif here