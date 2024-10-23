/*
Question 7: Write a simple program to print the created thread IDs.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/


#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>

void *sample(){
    printf("Running in thread with thread ID %lu\n",pthread_self());
    //  The pthread_self() function returns the ID of the calling thread.
    // This is the same value that is returned in *thread in the
    // pthread_create(3) call that created this thread.

    exit(0);
}
void main(){
pthread_t threadID;
// pthread_create(&threadID,iskeattribue,(void*)sample,iskadata)
if(pthread_create(&threadID,NULL,(void*)sample,NULL))
 perror("error");
 pthread_exit(NULL);
}

/*Running in thread with thread ID 131692197054016

*/
