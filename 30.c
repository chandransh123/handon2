/* Question 30: Write a program to create a shared memory. 
    1. Write some data to the shared memory
    2. Attach with `O_RDONLY` and check whether you are able to overwrite. 
    3. Detach the shared memory 
    4. Remove the shared memory
*/

#include <sys/types.h> // Import for `ftok`, `shmget`, `shmat`
#include <sys/ipc.h>   // Import for `ftok`, `shmget`
#include <sys/shm.h>   // Import for `shmget`, `shmat`
#include <unistd.h>    // Import for `_exit`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    key_t key;         // Key used to create / access Shared Memory
    int shimid;    // Identifier for the Shared Memory
    ssize_t size = 20; // Size of the Shared Memory
    char *shimPointer, *rshimpointer;

    key = ftok(".", 1);

    if (key == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    shimid = shmget(key, size, IPC_CREAT | 0700); // Create the shared memory if it doesn't exist; if it exists use the existing one

    if (shimid == -1)
    {
        perror("Error while getting Shared Memory!");
        _exit(0);
    }
    // ======================== 1 ========================
    shimPointer = shmat(shimid, (void *)0, 0);

    if (*shimPointer == -1)
    {
        perror("Error while attaching address space!");
        _exit(0);
    }

    printf("Press enter to write to the shared memory!\n");
    getchar();

    sprintf(shimPointer, "Yolo"); // Writing to the shared memory

    printf("Press enter to read from the shared memory!\n");
    getchar();

    printf("Data from shared memory: %s\n", shimPointer); // Reading from the shared memory

    // ===================================================

    // ======================== 2 ========================

    rshimpointer = shmat(shimid, (void *)0, SHM_RDONLY);
    if (*rshimpointer == -1)
    {
        perror("Error while attaching address space!");
        _exit(0);
    }
    
    // printf("Press enter to write to the shared memory!\n");
    // getchar();

    // The below line will cause a segmentation fault (uncomment to get the required output)
    // sprintf(rshimpointer, "Yolo"); // Writing to the shared memory

    printf("Press enter to read from the shared memory!\n");
    getchar();

    printf("Data from shared memory: %s\n", rshimpointer); // Reading from the shared memory

    // ===================================================

    // ======================== 3 ========================
    printf("Detaching pointer to shared memory!\n");
    shmdt(shimPointer);       // Dettach pointer to Shared Memory
    shmdt(rshimpointer); // Dettach pointer to Shared Memory
    // ===================================================

    // ======================== 4 ========================
    printf("Press enter to delete the shared memory!\n");
    getchar();

    // Delete Shared Memory
    shmctl(shimid, IPC_RMID, NULL);
    // ===================================================
}
/*
Shared memory created with ID: 39
Data written to shared memory: Hello, Shared Memory!
Shared memory detached after writing.
Data read from shared memory (read-only): Hello, Shared Memory!
Attempting to overwrite in read-only mode...
Segmentation fault (core dumped)*/