
/*---
Question 21a
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
    int fifo1FD1, fifo1FD2;
    char data[100];

    init();

    fifo1FD1 = open(fifoOneName, O_WRONLY);
    if (fifo1FD1 == -1)
    {
        perror("Error while opening fifoOne");
        _exit(0);
    }

    fifo1FD2 = open(fifoTwoName, O_RDONLY);
    if (fifo1FD1 == -1)
    {
        perror("Error while opening fifoTwo");
        _exit(0);
    }

    writebyte = write(fifo1FD1, "From 21a to 21b", 15);

    if (writebyte == -1)
        perror("Error while writing to FIFO fifoOne!");

    close(fifo1FD1);

    readbyte = read(fifo1FD2, &data, 100);

    if (readbyte == -1)
    {
        perror("Error while reading from FIFO fifoTwo!");
        _exit(0);
    }

    printf("Data from FIFO: %s\n", data);

    close(fifo1FD2);
}
/*
Data from FIFO: From 21b to 21a*/