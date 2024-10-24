// #include <stdio.h>
// #include<sys/types.h>
// #include<unistd.h>

// int main(){
//     printf("hello linux\n");
//   printf("process ID=%d",getpid());
//     return 0;
  
// }
// #include <stdio.h>
// #include<unistd.h>
// int main(){
//     printf("before forking\n");
//     fork();
//     printf("after forking\n");
// }
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    int pid;
    pid=fork();
    if(pid==0){
        // printf("in child process\n");
        // //code to play animated gif
        // printf("child :child's PID:%d\n",getpid());
        // printf("child:parent's PID:%d\n",getppid());
        execl("/bin/ls","-al","/etc",NULL);
        printf("child:after exec()\n");

    }
    else{
        printf("in parent process\n");
        printf("parent:parent PID:%d\n",getpid());
        printf("parent:parent PID:%d\n",pid);
        //code to copy file


    }
    return 0;
}
//Imp command ps -A gives list of all running processes
