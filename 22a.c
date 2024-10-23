

/*---
Question 22a
: Write a program to wait for data to be written into FIFO within 10 seconds, use `select` system call with FIFO.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <sys/types.h> // Import for `open`, `select`
#include <sys/stat.h>  // Import for `open`
#include <fcntl.h>     // Import for `open`
#include <sys/time.h>  // Import for `select`
#include <unistd.h>    // Import for `select`, `read`
#include <stdio.h>     // Import for `perror`

#include "./22-global.h" // Import for FIFO file name

void main()
{
    int fD, readbytes;
    char data[100];

    fd_set readFDSet;
    struct timeval timer;
    int selectState;

    init();

    fD = open(fifoName, O_NONBLOCK | O_RDONLY);

    if (fD == -1)
    {
        perror("Error while opening FIFO file!");
        _exit(0);
    }

    FD_ZERO(&readFDSet);
    FD_SET(fD, &readFDSet); // Adding FIFO file's descriptor to the set of file descriptors to read from

    // Setting the time to wait to 10s
    timer.tv_sec = 10;
    timer.tv_usec = 0;

    selectState = select(fD + 1, &readFDSet, NULL, NULL, &timer);

    if (selectState == -1)
        perror("Error while calling for select!");
    else if (selectState)
    {
        readbytes = read(fD, &data, 100);

        if (readbytes == -1)
            perror("Error while reading from FIFO!");
        else
            printf("Data received : %s\n", data);
    }
    else
        printf("You didn't send any data for 10 seconds! :(\n");

    close(fD);
}