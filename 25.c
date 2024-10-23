/* /*---
Question 25
: Write a program to print a message queue's (use `msqid_ds` and `ipc_perm` structures)
    1. Access permission 
    2. `uid`, `gid` 
    3. Time of last message sent and received 
    4. Time of last change in the message queue
    5. Size of the queue 
    6. Number of messages in the queue
    7. Maximum number of bytes allowed
    8. PID of the `msgsnd` and `msgrcv`
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/

#include <sys/types.h> // Import for `ftok` `msgget` & `msgctl`
#include <sys/ipc.h>   // Import for `ftok` `msgget` & `msgctl`
#include <sys/msg.h>   // Import for `msgget` & `msgctl`
#include <stdio.h>     // Import for `perror` & `printf`
#include <unistd.h>    // Import for `_exit`
#include <errno.h>     // Import for `errno`

void main()
{
    key_t queuekey;                   // IPC (Message Queue) key
    int queueid;              // IPC (Message Queue) identifier
    struct msqid_ds msgqueue; // IPC (Message Queue) information
    int msgctlstate;                 // Determines success of `msgctl` call

    queuekey = ftok(".", 1);

    if (queuekey == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    queueid = msgget(queuekey, IPC_CREAT | 0700);
    if (queueid == -1)
    {
        perror("Error while creating Message Queue!");
        _exit(0);
    }

    printf("Key: %d\n", queuekey);
    printf("Message Queue Identifier: %d\n\n", queueid);

    msgctlstate = msgctl(queueid, IPC_STAT, &msgqueue);

    if (msgctlstate == -1)
    {
        perror("Error while getting Message Queue info!");
        _exit(0);
    }

    printf("Access Permission: %od\n", msgqueue.msg_perm.mode);
    printf("UID: %d\n", msgqueue.msg_perm.uid);
    printf("GID: %d\n", msgqueue.msg_perm.gid);
    printf("Time of last message sent: %ld\n", msgqueue.msg_stime);
    printf("Time of last message received: %ld\n", msgqueue.msg_rtime);
    printf("Size of queue: %ld\n", msgqueue.__msg_cbytes);
    printf("Number of messages in the queue: %ld\n", msgqueue.msg_qnum);
    printf("Maximum number of bytes allowed in the queue: %ld\n", msgqueue.msg_qbytes);
    printf("PID of last sent message: %d\n", msgqueue.msg_lspid);
    printf("PID of last received message: %d\n", msgqueue.msg_lrpid);
}
/*
Key: 17181662
Message Queue Identifier: 0

Access Permission: 700d
UID: 1000
GID: 1000
Time of last message sent: 0
Time of last message received: 0
Size of queue: 0
Number of messages in the queue: 0
Maximum number of bytes allowed in the queue: 16384
PID of last sent message: 0
PID of last received message: 0*/