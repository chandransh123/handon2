
/*
Question 31b
  : Write a program to create a ssemaphores and initialize value to the ssemaphores. - Create a counting semaphores
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

#define MAX_RESOURCES 3  // Number of resources (semaphores count)

sem_t semaphores;  // Counting semaphores declaration

// Function to simulate resource access
void* access_resource(void* thread_id) {
    long tid = (long)thread_id;

    // Wait (P operation) to acquire the semaphores
    printf("Thread %ld is waiting to access a resource...\n", tid);
    sem_wait(&semaphores);

    // Simulate resource access (critical section)
    printf("Thread %ld has acquired a resource.\n", tid);
    sleep(2);  // Simulate resource usage by the thread
    printf("Thread %ld is releasing the resource.\n", tid);

    // Signal (V operation) to release the semaphores
    sem_post(&semaphores);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    long i;

    // Initialize the semaphores with a count of MAX_RESOURCES
    // This means a maximum of MAX_RESOURCES threads can access the resource concurrently
    if (sem_init(&semaphores, 0, MAX_RESOURCES) != 0) {
        perror("Failed to initialize semaphores");
        return 1;
    }

    // Create multiple threads that will try to access the shared resource
    for (i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, access_resource, (void*)i);
    }

    // Wait for all threads to finish
    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphores after all threads are done
    if (sem_destroy(&semaphores) != 0) {
        perror("Failed to destroy semaphores");
        return 1;
    }

    printf("Semaphore has been successfully destroyed.\n");

    return 0;
}
/*
Thread 0 is waiting to access a resource...
Thread 0 has acquired a resource.
Thread 1 is waiting to access a resource...
Thread 1 has acquired a resource.
Thread 2 is waiting to access a resource...
Thread 2 has acquired a resource.
Thread 3 is waiting to access a resource...
Thread 4 is waiting to access a resource...
Thread 0 is releasing the resource.
Thread 1 is releasing the resource.
Thread 3 has acquired a resource.
Thread 4 has acquired a resource.
Thread 2 is releasing the resource.
Thread 3 is releasing the resource.
Thread 4 is releasing the resource.
Semaphore has been successfully destroyed.*/