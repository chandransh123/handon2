
/*---
Question 21b
: Write two programs so that both can communicate by FIFO - Use two way communications.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <sys/types.h> // Import for & `open`
#include <sys/stat.h>  // Import for & `open`
#include <fcntl.h>     // Import for `open`
#include <unistd.h>    // Import for `write`
#include <stdio.h>     // Import for `perror`

#include "./21-global.h" // Import for FIFO file name & `init` function

void main()
{
    int readbyte, writebyte;
    int fifoOneFD1, fifoTwoFD2;
    char data[100];

    init();

    fifoOneFD1 = open(fifoOneName, O_RDONLY);
    if (fifoOneFD1 == -1)
    {
        perror("Error while opening fifoOne");
        _exit(0);
    }

    fifoTwoFD2 = open(fifoTwoName, O_WRONLY);
    if (fifoOneFD1 == -1)
    {
        perror("Error while opening fifoTwo");
        _exit(0);
    }

    writebyte = write(fifoTwoFD2, "From 21b to 21a", 15);

    if (writebyte == -1)
        perror("Error while writing to FIFO fifoOne!");

    close(fifoTwoFD2);

    readbyte = read(fifoOneFD1, &data, 100);

    if (readbyte == -1)
    {
        perror("Error while reading from FIFO fifoOne!");
        _exit(0);
    }

    printf("Data from FIFO: %s\n", data);

    close(fifoOneFD1);
}
// Data from FIFO: From 21a to 21b