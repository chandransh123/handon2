/*---
Question 26
: Write a program to send messages to the message queue. Check `ipcs -q`
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_TEXT 512  // Maximum text size for the message

// Structure for message queue
struct message {
    long message_type;         // Message type, must be > 0
    char message_text[MAX_TEXT];  // Message content
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    // Generate a unique key for the message queue
    key = ftok("msgqueuefile", 65);  // 'msgqueuefile' should be an existing file on your system
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a message queue with read/write permissions
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Prepare the message
    msg.message_type = 1;  // Message type must be positive (used to prioritize messages)
    strcpy(msg.message_text, "Hello, this is a message from the sender!");

    // Send the message to the queue
    if (msgsnd(msgid, &msg, sizeof(msg.message_text), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent to queue: %s\n", msg.message_text);
    printf("Use 'ipcs -q' to check the message queue.\n");

    return 0;
}
