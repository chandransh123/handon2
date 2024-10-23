
/*---
Question 9
 : Write a program to ignore a `SIGINT` signal then reset the default action of the `SIGINT` signal - Use `signal` system call.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <signal.h>
#include<stdio.h>
#include<unistd.h>
void sampleFunction(){
    printf("Signal SIGINT has been caught");
}
void main(){
   
    __sighandler_t signalstate;// determine the success of the signal call
    //Ignore SIGINT
    printf("Your SIGINT will be ignored for 5 sec");
    signalstate=signal(SIGINT,SIG_IGN);
    if(signalstate==SIG_ERR){
        perror("error while trying to ignore signal" );
    }
    else 
    sleep(5);



    printf("SIGINT will now be caught\n");
    signalstate=signal(SIGINT,(void *)sampleFunction);
    if(signalstate==SIG_ERR)
    perror("error while assigning signal handler");
    else
    sleep(5);



    printf("SIGINT will now be caught using the default handler\n");
    signalstate=signal(SIGINT,SIG_DFL);
    if(signalstate==SIG_ERR)
    perror("error");
    else 
    sleep(5);
}
/*
Your SIGINT will be ignored for 5 secSIGINT will now be caught
SIGINT will now be caught using the default handler
*/