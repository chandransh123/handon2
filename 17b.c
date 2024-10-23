
/*---
 Question 17b
 : Write a program to execute `ls -l | wc`. Use `dup2`
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <unistd.h>    // Import for `pipe`, `fork`, `execl` & `dup`
#include <sys/types.h> // Import `fork`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    // File descriptor used for pipe operations
    int pipefd1[2];  // pipefd1[0] -> read, pipefd1[1] -> write
    int pipestate; // // Variable used to determine success of `pipe` call
    pid_t childPid1;

    pipestate = pipe(pipefd1);

    if (pipestate == -1)
        perror("Error while creating the file!");
    else
    {
        childPid1 = fork();

        if (childPid1 == -1)
            perror("Error while forking child!");
        else if (childPid1 == 0)
        {
            // Child will enter this branch
            close(STDIN_FILENO);
            dup(pipefd1[0]); // STDIN will be reassigned to pipefdp[0]
            close(pipefd1[1]);
            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            // Parent will enter this branch
            close(STDOUT_FILENO);
            dup(pipefd1[1]); // STDOUT will be reassigned to pipefd1[1]
            close(pipefd1[0]);
            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
}
/*
   111     992    6538*/












