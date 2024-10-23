
/*---
Question 22b
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

#include "./22-global.h"

void main()
{
    int fD, writebyte;
    char data[100];

   fD = open(fifoName, O_NONBLOCK | O_WRONLY);

    if (fD == -1)
    {
        perror("Error while opening FIFO file!");
        _exit(0);
    }

    writebyte = write(fD, "Hello there...", 14);

    if (writebyte == -1)
        perror("Error while writing to FIFO!");

    close(fD);
}
/*
You didn't send any data for 10 seconds!*/