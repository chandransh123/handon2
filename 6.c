/*
Question 6
// Question : Write a simple program to create three threads.
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include<pthread.h>//for threads
#include<stdio.h>
#include<unistd.h>
void *sample(void *data){
    printf("running in thread:%lu\n",pthread_self());

}
void main(){
    // creating thread
    pthread_t threadone,threadtwo,threadthree;
    //if(pthread_create(&threadone,threadattribute,sample,fuctionattributes)
    if(pthread_create(&threadone,NULL,sample,NULL))
    perror("not created");
     if(pthread_create(&threadtwo,NULL,sample,NULL))
    perror("not created");
    if(pthread_create(&threadthree,NULL,sample,NULL))
    perror("not created");
// wait for the threads to terminate and then terminate the main process
pthread_exit(0);
}
/*
running in thread:137156232218176
running in thread:137156221732416
running in thread:137156211246656
*/