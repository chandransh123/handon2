/*---
 Question 23: Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/

#include <unistd.h>    // Import for `sysconf`, `sysconf`
#include <sys/types.h> // Import for `mkfifo`
#include <sys/stat.h>  // Import for `mkfifo`
#include <stdio.h>     // Import for `perrore & `printf`
#include <errno.h>     // Import for `errno`
void main(){
    int fifostate;
    long maxfile;
    long size;
    char *fifoname="23-fifo";
    fifostate=mkfifo(fifoname,S_IRWXU);

if(!(errno ==EEXIST|| fifostate!=1))
      perror("error");
else{
    maxfile=sysconf(_SC_OPEN_MAX);
    if(maxfile==-1)
       perror("error while using sysconf");
    else 
    printf("maximum number of files that can be opened is %ld\n",maxfile);
    size=pathconf(fifoname,_PC_PIPE_BUF);
    if(size==-1)
    perror("Error while calling pathconf");
    else
    printf("Maximum size of pipe :%ld\n",size);

}





}
/*
maximum number of files that can be opened is 1048576
Maximum size of pipe :4096
*/