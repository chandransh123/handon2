
/*---
 Question 18
  : Write a program to find out total number of directories on the `pwd`. Execute `ls -l | grep ^d | wc`. Use only `dup2`.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <unistd.h>    // Import for `pipe`, `dup2`, `fork`, `exec`
#include <sys/types.h> // Import for `fork`
#include <stdio.h>     // Import for `perror`

void main()
{
    int pipecmd1to2[2], pipeCmd2To3[2]; // fd[0] -> read, fd[1] -> write
    int pipe1state,pipe2state;

    pid_t child1, child2;

    pipe1state = pipe(pipecmd1to2);
   pipe2state = pipe(pipeCmd2To3);

    if (pipe1state == -1 ||pipe2state)
        perror("Error while creating the pipe!");
    else
    {
        child1 = fork();

        if (child1 == -1)
            perror("Error while creating first child!");
        else if (child1 == 0)
        {
            // Child One will enter this branch
            close(pipeCmd2To3[1]); // Close the write end of the pipe
            close(pipecmd1to2[0]);
            close(pipecmd1to2[1]);

            close(STDIN_FILENO);
            dup2(pipeCmd2To3[0], STDIN_FILENO);

            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            // Parent will enter this branch
            child2 = fork();

            if (child2 == -1)
                perror("Error while creating second child!");
            else if (child2 == 0)
            {
                // Child Two will enter this branch

                close(pipecmd1to2[1]); // Close the write end of the pipe
                close(pipeCmd2To3[0]);

                close(STDIN_FILENO);
                dup2(pipecmd1to2[0], STDIN_FILENO);
                close(STDOUT_FILENO);
                dup2(pipeCmd2To3[1], STDOUT_FILENO);

                execl("/usr/bin/grep", "grep ^d", "^d", NULL);
            }
            else
            {
                // Parent will enter this branch

                // Parent will execute the `ls -l` command
                close(pipecmd1to2[0]); // Close the read end of the pipe
                close(pipeCmd2To3[1]);
                close(pipeCmd2To3[0]);

                close(STDOUT_FILENO); // Close the file descriptor to the standard output
                dup2(pipecmd1to2[1], STDOUT_FILENO); // Reassign standard output to pipe output

                execl("/usr/bin/ls", "ls -l", "-l", NULL);
            }
        }
    }
}
/*
     0       0       0*/