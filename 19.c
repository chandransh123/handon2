
/*---
 Question 19
 : Create a FIFO file by `mkfifo` library function and `mknod` system call
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <sys/types.h> // Import for `mkfifo` library function & `mknod` system call
#include <sys/stat.h>  // Import for `mkfifo` library function & `mknod` system call
#include <fcntl.h>     // Import for `mknod` system call
#include <unistd.h>    // Import for `mknod` system call
#include <stdio.h>     // Import for using `printf` & `perror` function

void main()
{
    char *mkdfifoname = "./mymkfifo";    // File name of FIFO file created using `mkfifo`
    char *mknodname = "./mymknod-fifo"; // File name of FIFO file created using `mknod`

    int mkfifo_state, mknod_state; // 0 -> Success, -1 -> Error

    // Using `mkfifo` library function
    mkfifo_state = mkfifo(mkdfifoname, S_IRWXU);

    if (mkfifo_state == -1)
        perror("Error while creating FIFO file!");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");

    // Using `mknod` system call
    mkfifo_state = mknod(mknodname, __S_IFIFO | S_IRWXU, 0);

    if (mknod_state == -1)
        perror("Error while creating FIFO file!");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");
}
/*
Succesfully created FIFO file. Check using `ll` or `ls -l` command!
Succesfully created FIFO file. Check using `ll` or `ls -l` command!*/