
/*---
Question 13b
 : Write two programs: first program is waiting to catch `SIGSTOP` signal, the second program will send the signal (using `kill` system call). Find out whether the first  program is able to catch the signal or not.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
// This program sends the `SIGSTOP` signal

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    // Replace with the process ID of the signal catcher
    pid_t pid;
    printf("Enter the PID of the signal catcher: ");
    scanf("%d", &pid);

    // Send SIGUSR1 to the catcher
    if (kill(pid, SIGUSR1) == -1) {
        perror("Failed to send signal");
        return 1;
    }

    printf("SIGUSR1 signal sent to process %d\n", pid);
    return 0;
}
/*
pass the pid of the process to whom the SIGSTOP signal is to be sent*/
