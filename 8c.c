/*
// Question 8c: Write a separate program using signal system call to catch `SIGFPE`
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <signal.h>//import for signal
#include<stdio.h>//import for 'printf',,scanf &'perror'
#include<unistd.h>//import for '__exit
void callback(){
    printf("signal SIGFPE has been caught!\n");
    _exit(0);
}
void main(){
    __sighandler_t status;//determine the success of the signal call
      status=signal(SIGFPE,(void *)callback);
      if(status==SIG_ERR)
      perror("error while assigning signal handler");
      else 
           raise(SIGFPE);
         }
/*
output
signal SIGFPE has been caught!
NOTES:-SIGFPE is a signal in Unix-like operating systems that is sent to a process when it performs an erroneous arithmetic operation, specifically a floating-point exception or other math-related error. Despite the name "Floating-Point Exception," this signal covers a range of arithmetic errors,
*/