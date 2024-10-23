/*---
Question 24
Write a program to create a message queue and print the key and message queue id
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <sys/types.h> // Import for `ftok` & `msgget`
#include <sys/ipc.h>   // Import for `ftok` & `msgget`
#include <sys/msg.h>   // Import for `msgget`
#include <stdio.h>     // Import for `perror` & `printf`
#include <unistd.h>    // Import for `_exit`
#include <errno.h>     // Import for `errno`
void main(){
    key_t queuekey;//IPC (Message Queue)key
    int queueId;//IPC (Message Queue)identifier
    queuekey=ftok(".",1);
    if(queuekey==-1){
        perror("error while computing key");
        _exit(0);
    }
    queueId=msgget(queuekey,IPC_CREAT|IPC_EXCL|0700);
    if(queueId== -1){
        perror("error while creating message queue");
        _exit(0);
    }
    printf("key:%d\n",queuekey);
    printf("message queue identifer:%d\n",queueId);
    
}
/*
key:17181662
message queue identifer:0*/