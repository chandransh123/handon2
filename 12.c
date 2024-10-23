
/*---
Question 12
 :  Write a program to create an orphan process. Use `kill` system call to send `SIGKILL` signal to the parent process from the child process
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<stdio.h>
void main(){
    pid_t childPid ,parentPid;
    int killstatus;
    childPid=fork();
    if(childPid==-1){
        perror("error while creating child");

    }
    else if(!childPid){
        // child will enter this branch
        printf("child PID:%d\n",getpid());
        printf("Parent PID:%d\n",getppid());
        sleep(10);
        killstatus=kill(getppid(),SIGKILL);
        if(!killstatus){
            printf("successfully killed parent\n");
            sleep(10);
            printf("child now exiting");
        }
        else{
            perror("error");
        }}
        else {
            // parent will enter here
while(1);
        }
    }
    /*
child PID:3663
Parent PID:3662
Killed
chandransh@chandransh-HP-Laptop-14s-fq1xxx:~/linuxlab2$ successfully killed parent
child now exiting
*/
