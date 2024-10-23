/*
Question 8d :Write a separate program using signal system call to catch `SIGALRM` (use `alarm` system call)

NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <signal.h>//import for signal
#include<stdio.h>//import for 'printf',,scanf &'perror'
#include<unistd.h>//import for '__exit
void callback(){
    printf("signal SIGALRM has been caught!\n");
    _exit(0);
}
void main(){
    __sighandler_t status;//determine the success of the signal call
      alarm(1);//set the alarm for 1sS
      status=signal(SIGALRM,(void *)callback);
      if(status==SIG_ERR)
           perror("error while assigning signal handler");
      else 
           while(1);
         }
/*
signal SIGALRM has been caught!
*/