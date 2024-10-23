
/*
Question 4
Write a program to find out time taken to execute getppid system call. Use time stamp counter.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <sys/time.h>//import for gettimeof day system call
#include<sys/types.h> // import for 'getpid' system call
#include <unistd.h>//import for 'getpid' system call
#include <stdio.h>//import for printf

// import for __rdtsc()
#ifdef _MSC_VER
#include <intrin.h>//microsrt ke liye
#else 
#include <x86intrin.h>
#endif
 void main(){
    int start ,end,pid;
    struct timeval timestamp;
    // struct timeval {
    // long tv_sec;  // seconds
    // long tv_usec; // microseconds
    int iter=0;
    start=__rdtsc();
    while(iter<100){
        pid=getppid();
        iter++;
    }
    end=__rdtsc();
    printf("PID:%d\n",pid);
    printf("TSC FOR 100th process  %d\n",(int)((end-start)/2.4));

};
/*Output
PID:10904
TSC FOR 100th process26678

*/

 


























