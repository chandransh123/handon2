
/*---
Question 10c
// Question : Write a separate program using sigaction system call to catch `SIGFPE` signal
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
    int state;// determine succes of sigction call
    struct sigaction actions;

    // Setting up the signal handler
    actions.sa_handler = signalHandler;
    actions.sa_flags = 0;

    state = sigaction(SIGINT, &actions, NULL);
    
    if (state == -1) {
        perror("Error setting signal handler");
    } else {
        // Raising SIGSEGV to trigger the handler
        raise(SIGFPE);
    }


}
/*
Floating point exception (core dumped)
*/