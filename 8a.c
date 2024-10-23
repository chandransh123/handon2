/*
// Question 8a : Write a separate program using signal system call to catch `SIGSEGV`
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <signal.h>//import for signal,raise
#include<stdio.h>//printf
#include<unistd.h>//import for exit
void *callback(){

    printf("Signal SIGNSEVG has been caught");
    _exit(0);
}
void main(){
    __sighandler_t x; // determine the success of the signal call
    x=signal(SIGSEGV,(void*)callback());
    if(x==SIG_ERR){

     perror("error while assigning signal handler");
    }
    else{
     raise(SIGSEGV);//send segment fault signal
    }

}







/*
Signal SIGNSEVG has been caught: Success
*/


/*
/*Note:__sighandler_t: The type of the handler function pointer (as seen internally) ensures the function takes an integer argument (the signal number) and returns nothing (void).
signal(): This function is used to set a signal handler for a specific signal (in this case, SIGSEGV for segmentation faults).*/