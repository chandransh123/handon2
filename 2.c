/*---
Question 2
Write a program to print the system resource limits. Use getrlimit system call.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>
void print(int resources ,const char *name1){
    struct rlimit limits; // structure rlimit contains both softlink and hardlink
    // function to call getrlimit 
    if(getrlimit(resources,&limits)==0){
       printf("%s: Soft limits = %ld, Hard limits = %ld\n", name1, (long)limits.rlim_cur, (long)limits.rlim_max);
    }
    else {
        perror("getrlimit");
    }
}
int main(){
    printf("system");
    print(RLIMIT_CPU,"CPU time");
    print(RLIMIT_FSIZE,"File Size");
    print(RLIMIT_DATA,"DATA");
    print(RLIMIT_STACK,"STACK");
    print(RLIMIT_CORE,"CORE");
    print(RLIMIT_RSS,"RSS");
    print(RLIMIT_NPROC,"NPROC");
    print(RLIMIT_NOFILE,"NOFILE");
    print(RLIMIT_MEMLOCK,"MEMLOCK");
    print(RLIMIT_AS,"AS");
    return 0;
}
/*OUTPUT
systemCPU time: Soft limits = -1, Hard limits = -1
File Size: Soft limits = -1, Hard limits = -1
DATA: Soft limits = -1, Hard limits = -1
STACK: Soft limits = 8388608, Hard limits = -1
CORE: Soft limits = 0, Hard limits = -1
RSS: Soft limits = -1, Hard limits = -1
NPROC: Soft limits = 28718, Hard limits = 28718
NOFILE: Soft limits = 1024, Hard limits = 1048576
MEMLOCK: Soft limits = 951013376, Hard limits = 951013376
AS: Soft limits = -1, Hard limits = -1
chandransh@chandransh-HP-Laptop-14s-fq
*/



















