
/*
Question 31a
  : Write a program to create a semaphores and initialize value to the semaphores - Create a binary semaphores
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <sys/types.h> // Import for `ftok`, `semget`, `semctl`
#include <sys/ipc.h>   // Import for `ftok`, `semget`, `semctl`
#include <sys/sem.h>   // Import for `semget`, `semctl`
#include <unistd.h>    // Import for `_exit`
#include <stdio.h>     // Import for `perror` & `printf`

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t binarysemaphore;  // Binary semaphores declaration

// Function to simulate resource access
void* access_critical_section(void* threadid) {
    long tid = (long)threadid;

    // Wait (P operation) to acquire the binary semaphores
    printf("Thread %ld is waiting to enter the critical section...\n", tid);
    sem_wait(&binarysemaphore);

    // Critical section starts
    printf("Thread %ld has entered the critical section.\n", tid);
    sleep(2);  // Simulate critical section work
    printf("Thread %ld is leaving the critical section.\n", tid);
    // Critical section ends

    // Signal (V operation) to release the binary semaphores
    sem_post(&binarysemaphore);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    long i;

    // Initialize the binary semaphores with a value of 1 (binary semaphores)
    if (sem_init(&binarysemaphore, 0, 1) != 0) {
        perror("Failed to initialize semaphores");
        return 1;
    }

    // Create multiple threads trying to access the critical section
    for (i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, access_critical_section, (void*)i);
    }

    // Wait for all threads to finish
    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphores after all threads are done
    if (sem_destroy(&binarysemaphore) != 0) {
        perror("Failed to destroy semaphores");
        return 1;
    }

    printf("Binary semaphores has been successfully destroyed.\n");

    return 0;
}
/*Thread 0 is waiting to enter the critical section...
Thread 0 has entered the critical section.
Thread 2 is waiting to enter the critical section...
Thread 1 is waiting to enter the critical section...
Thread 0 is leaving the critical section.
Thread 2 has entered the critical section.
Thread 2 is leaving the critical section.
Thread 1 has entered the critical section.
Thread 1 is leaving the critical section.
Binary semaphores has been successfully destroyed.
*/