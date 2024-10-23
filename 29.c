
/*
Question 29
:// Question : Write a program to remove the message queue.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main() {
    key_t keynum;
    int msgidqueue;

    // Generate a unique key
    keynum = ftok(".", 1);
    if (keynum == -1) {
        perror("ftok failed");
        exit(EXIT_FAILURE);
    }

    // Create or get the message queue ID
    msgidqueue = msgget(keynum, 0666 | IPC_CREAT);
    if (msgidqueue == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    printf("Message queue created or found successfully.\n");

    // Remove the message queue
    if (msgctl(msgidqueue, IPC_RMID, NULL) == -1) {
        perror("msgctl (IPC_RMID) failed");
        exit(EXIT_FAILURE);
    }

    printf("Message queue removed successfully.\n");

    return 0;
}
/*
Message queue created or found successfully.
Message queue removed successfully.*/