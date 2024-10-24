/*Question 32d
  : Write a program to implement semaphores to protect any critical section - Remove the created semaphores
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphores;  // Semaphore declaration
int shared_data = 0;  // Shared resource

// Function to simulate access to the critical section (shared resource)
void* access_shared_resource(void* thread_id) {
    long tid = (long)thread_id;

    // Wait (P operation) to acquire the semaphores
    sem_wait(&semaphores);

    // Critical section starts
    printf("Thread %ld is entering the critical section.\n", tid);
    int local_copy = shared_data;
    sleep(1);  // Simulate some work in the critical section
    local_copy += 10;
    shared_data = local_copy;
    printf("Thread %ld has modified shared data: %d\n", tid, shared_data);
    printf("Thread %ld is leaving the critical section.\n", tid);
    // Critical section ends

    // Signal (V operation) to release the semaphores
    sem_post(&semaphores);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    long i;

    // Initialize the semaphores with 1 (binary semaphores)
    if (sem_init(&semaphores, 0, 1) != 0) {
        perror("Failed to initialize semaphores");
        return 1;
    }

    // Create multiple threads to access the critical section
    for (i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, access_shared_resource, (void*)i);
    }

    // Wait for all threads to complete
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
/*Thread 0 is entering the critical section.
Thread 0 has modified shared data: 10
Thread 0 is leaving the critical section.
Thread 1 is entering the critical section.
Thread 1 has modified shared data: 20
Thread 1 is leaving the critical section.
Thread 2 is entering the critical section.
Thread 2 has modified shared data: 30
Thread 2 is leaving the critical section.
Thread 3 is entering the critical section.
Thread 3 has modified shared data: 40
Thread 3 is leaving the critical section.
Thread 4 is entering the critical section.
Thread 4 has modified shared data: 50
Thread 4 is leaving the critical section.
Semaphore has been successfully destroyed.
*/