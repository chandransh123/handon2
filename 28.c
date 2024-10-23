/*
Question 28
: Write a program to change the exiting message queue permission. (Use msqid_ds structure)
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main() {
    key_t keynumber;
    int msqueue;
    struct msqid_ds buffer;

    // Generate a unique keynumber
    keynumber = ftok(".", 1);
    if (keynumber == -1) {
        perror("ftok failed");
        exit(EXIT_FAILURE);
    }

    // Get the message queue identifier (assuming the queue already exists)
 msqueue = msgget(keynumber, 0666 | IPC_CREAT);

    if (msqueue == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    // Retrieve current message queue status
    if (msgctl(msqueue, IPC_STAT, &buffer) == -1) {
        perror("msgctl (IPC_STAT) failed");
        exit(EXIT_FAILURE);
    }

    // Display current permissions
    printf("Current permissions: %o\n", buffer.msg_perm.mode & 0777);

    // Change the permission to 0644 (owner: read/write, group: read, others: read)
    buffer.msg_perm.mode = 0644;

    // Set the updated permissions
    if (msgctl(msqueue, IPC_SET, &buffer) == -1) {
        perror("msgctl (IPC_SET) failed");
        exit(EXIT_FAILURE);
    }

    // Retrieve updated message queue status to verify the change
    if (msgctl(msqueue, IPC_STAT, &buffer) == -1) {
        perror("msgctl (IPC_STAT) failed");
        exit(EXIT_FAILURE);
    }

    // Display updated permissions
    printf("Updated permissions: %o\n", buffer.msg_perm.mode & 0777);

    return 0;
}
/*?Current permissions: 666
Updated permissions: 644*/