// Question : Write a program to implement semaphores to protect any critical section - Rewrite the ticket number creation program using semaphores
/*---
Question 
: Write a program to implement semaphore to protect any critical section - Rewrite the ticket number creation program using semaphore
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphores;  // Semaphore declaration
int ticket_number = 0;  // Shared resource (ticket number)

// Function to generate a ticket number (critical section)
void* generate_ticket(void* thread_id) {
    long tid = (long)thread_id;
    
    // Wait (P operation) to acquire the semaphores
    sem_wait(&semaphores);
    
    // Critical section starts
    ticket_number++;
    printf("Thread %ld is generating ticket number: %d\n", tid, ticket_number);
    
    // Simulate some processing delay
    sleep(1);
    
    // Critical section ends
    
    // Signal (V operation) to release the semaphores
    sem_post(&semaphores);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    long i;
    
    // Initialize the semaphores with 1 (binary semaphores)
    sem_init(&semaphores, 0, 1);
    
    // Create multiple threads to generate ticket numbers
    for (i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, generate_ticket, (void*)i);
    }
    
    // Wait for all threads to complete
    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Destroy the semaphores
    sem_destroy(&semaphores);
    
    return 0;
}
/*
Thread 0 is generating ticket number: 1
Thread 1 is generating ticket number: 2
Thread 2 is generating ticket number: 3
Thread 3 is generating ticket number: 4
Thread 4 is generating ticket number: 5*/
