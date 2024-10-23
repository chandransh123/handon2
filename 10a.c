

/*---
Question 10a
 : Write a separate program using sigaction system call to catch `SIGSEGV` signal
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void signalHandler(int signalNumber){
    printf("caught signal SIGSEGV (%d)\n",signalNumber);
    _exit(0);
}
int  main(){
    int status;
    struct sigaction action;
   
    action.sa_handler=signalHandler;
    action.sa_flags=0;
    status=sigaction(SIGSEGV,&action,NULL);
    if(status==-1){
        perror("error");
    }
else{
    raise (SIGSEGV);
}
}
/*
caught signal SIGSEGV (11)

*/
/*
struct sigaction {
    void (*sa_handler)(int);           // Pointer to signal handling function
    void (*sa_sigaction)(int, siginfo_t *, void *); // Extended signal handling function
    sigset_t sa_mask;                  // Signals to block during the handler execution
    int sa_flags;                      // Special flags to modify behavior
    void (*sa_restorer)(void);         // Deprecated, left for historical reasons
};

*/