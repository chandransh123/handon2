/*
Question 8f : Write a separate program using signal system call to catch `SIGVTALRM` (use `setitimer` system call)
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/


#include <signal.h>//import for signal
#include<stdio.h>//import for 'printf',,scanf &'perror'
#include<unistd.h>//import for '__exit
#include<sys/time.h>
void callback(){
    printf("signal SIGVTALRM has been caught!\n");
    _exit(0);
}
void main(){
  int timestate;
  __sighandler_t signalStatus;
  struct itimerval timer;
  //generate signal after 1s
  timer.it_value.tv_sec=1;
  timer.it_value.tv_usec=0;
  timer.it_interval.tv_sec=0;
  timer.it_interval.tv_usec=0;
  timestate=setitimer(ITIMER_VIRTUAL,&timer,0);
  if(timestate==-1){
    perror("error");
  }
  //catch the SIGALRM signal
  signalStatus=signal(SIGVTALRM,(void *)callback);
  if(signalStatus==SIG_ERR)
  perror("error");
  else 
  while(1);}
  /*signal SIGVTALRM has been caught!


*/
