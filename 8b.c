/*
// Question 8b : Write a separate program using signal system call to catch `SIGINT`
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <signal.h>//import for signal
#include<stdio.h>//import for 'printf',,scanf &'perror'
#include<unistd.h>//import for '__exit
void callback(){
    printf("signal SIGINT has been caught!\n");
    _exit(0);
}
void main(){
    __sighandler_t status;//determine the success of the signal call
      status=signal(SIGINT,(void *)callback);
      if(status==SIG_ERR)
      perror("error while assigning signal handler");
      else 
      while(1);
         }
/*
output
signal SIGINT has been caught!
Note:-ChatGPT

SIGINT is a signal in Unix-like operating systems that is sent to a process when the user issues an interrupt signal, typically by pressing Ctrl+C in the terminal. This signal is used to gracefully interrupt and stop a running process.
*/