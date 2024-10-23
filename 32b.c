/*Question 32b
: Write a program to implement semaphores to protect any critical section - Protect shared memory from concurrent write access
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphores;  // Semaphore declaration
int shared_data = 0;  // Shared resource (shared memory)

// Function to write to the shared memory (critical section)
void* write_to_shared_memory(void* thread_id) {
    long tid = (long)thread_id;

    // Wait (P operation) to acquire the semaphores
    sem_wait(&semaphores);

    // Critical section: writing to shared memory
    int local_copy = shared_data;
    printf("Thread %ld: Reading shared data: %d\n", tid, local_copy);

    // Simulate a write operation (modify shared data)
    local_copy += 10;
    printf("Thread %ld: Writing to shared data: %d\n", tid, local_copy);
    
    // Simulate some delay
    sleep(1);
    
    // Write the updated value back to shared memory
    shared_data = local_copy;

    // Signal (V operation) to release the semaphores
    sem_post(&semaphores);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    long i;

    // Initialize the semaphores with 1 (binary semaphores)
    sem_init(&semaphores, 0, 1);

    // Create multiple threads to write to the shared memory
    for (i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, write_to_shared_memory, (void*)i);
    }

    // Wait for all threads to complete
    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final value of shared data: %d\n", shared_data);

    // Destroy the semaphores
    sem_destroy(&semaphores);

    return 0;
}
/*
Thread 0: Reading shared data: 0
Thread 0: Writing to shared data: 10
Thread 1: Reading shared data: 10
Thread 1: Writing to shared data: 20
Thread 2: Reading shared data: 20
Thread 2: Writing to shared data: 30
Thread 3: Reading shared data: 30
Thread 3: Writing to shared data: 40
Thread 4: Reading shared data: 40
Thread 4: Writing to shared data: 50*/
