
/*---
Question 13a
 : Write two programs: first program is waiting to catch `SIGSTOP` signals, the second program will send the signals (using `kill` system call). Find out whether the first  program is able to catch the signals or not.

NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signals) {
    if (signals == SIGUSR1) {
        printf("Received SIGUSR1 signals!\n");
        exit(0);  // Exit after catching the signals
    }
}

int main() {
    // Register signals handler for SIGUSR1
    signals(SIGUSR1, handle_signal);

    printf("Process ID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signals...\n");

    // Wait indefinitely
    while (1) {
        pause();  // Suspend the process until a signals is received
    }

    return 0;
}

/*
Process ID:92325
error while catching signals: Invalid argument
putting the process to sleep for 15s
*/