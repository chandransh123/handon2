
/*---
Question 14
 : Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include<unistd.h>//import for pipe,write &read system call
#include<stdio.h>//Import for 'perror' and printf
void main(){
    int pipefd[2];  //pipefd[0]->read ,pipefd[1]->write;
    char *writebuf="krishna";//Data send through the pipe
    char *readbuf;
    int pipestate ;//variable used to determine if pipe is successful or not
    int readpipe ,writepipe;
    //creating a pipe;
    pipestate=pipe(pipefd);
    if(pipestate==-1){
        perror("error while creating the file");

    }
    else {
        printf("writing to th pipe\n");
        writepipe=write(pipefd[1],&writebuf,sizeof(writebuf));
        if(writepipe==-1){
            perror("error while writing the pipe\n");
            }
            else{
                printf("now reading from the pipe\n");
                readpipe=read(pipefd[0],&readbuf,writepipe);
                if(readpipe==-1){
                    perror("error while reading from pipe");
                }
                else{
                    printf("data from pipe:%s\n",readbuf);
                }
            }
        }
        /*
writing to th pipe
now reading from the pipe
data from pipe:krishna
*/
    }




