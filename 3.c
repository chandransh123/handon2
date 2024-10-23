/*---
Question 3
Write a program to set (any one) system resource limits. Use setrlimit system call.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>
int main(){
    struct rlimit limits;
    // get the curretnt resource limits for the number of open files
    if(getrlimit(RLIMIT_NOFILE,&limits)==0){
        printf("current limits :Soft =%ld,Hard=%ld\n ",(long)limits.rlim_cur,(long)limits.rlim_max);
    }
    else{
        perror("getlimit");
        return 1;
    }
    // set a new soft limits
    limits.rlim_cur=512;//soft limits
    limits.rlim_max=1024;// hard limits
    // set the new resouce limits
    if(setrlimit(RLIMIT_NOFILE,&limits)==0){
        printf("net limits set: soft=%ld ,Hard=%ld\n",(long)limits.rlim_cur,(long)limits.rlim_max);
    }
    else{
        perror("error");
        return 1;
    }
    return 0;
}
/*
output
current limits :Soft =1024,Hard=1048576 
net limits set: soft=512 ,Hard=1024

*/

