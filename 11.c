
/*---
Question 11
 : Write a program to ignore a `SIGINT` signal then reset the default action of the `SIGINT` signal - use `sigaction` system call.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void signalHandler(int signalNumber) {
    printf("Caught signal SIGSEGV (%d)\n", signalNumber);
    _exit(0);
}

void main() {
    int status;// determine succes of sigction call
    struct sigaction action;

//ignore SIGINT
    action.sa_handler = SIG_IGN;
    action.sa_flags = 0;

    status = sigaction(SIGINT, &action, NULL);
    
    if (status == -1) {
        perror("Error setting signal handler");
    } else {

        sleep(5);
    }
    //provide custom handler
    printf("handling SIGINT for 5 more sec \n");
    action.sa_handler=signalHandler;
    action.sa_flags=0;
    status=sigaction(SIGINT,&action,NULL);
    if(status==-1){
        perror("error");
    }
    else sleep(5);
    //setting default handler
    printf("Default action for SIIGINT for 5 second");
    action.sa_handler=SIG_DFL;
    action.sa_flags=0;
    status=sigaction(SIGINT,&action,NULL);
    if(status==-1){
        perror("error while setting signal handler");
    }
    else
    sleep(5);


}
/*
handling SIGINT for 5 more secDEfault action for SiIGINT for 5 second
*/