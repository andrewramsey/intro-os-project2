// Author: Andrew Ramsey 
// OU 4x4: rams0040   
// OU ID: 113546093
// VM Username: cs105                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          project1.c                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         // Andrew Ramsey rams0040
// Header          
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

// Shared memory struct
typedef struct
{
    int value;
} shared_mem;

// Creates the pointer total which points to the int value of shared memory
shared_mem *total;

// This process increments the shared memory by 100,000, then prints the total (shared mem) when done, no return type
void process1()
{
    for (int i = 0; i < 100000; i++) {
        total->value++;
    }
    printf("From Process 1: counter = %d.\n", total->value);
    exit(0);  // Exit child process
}

// Same as process 1
void process2()
{
    for (int i = 0; i < 100000; i++) {
        total->value++;
    }
    printf("From Process 2: counter = %d.\n", total->value);
    exit(0);
}

// Same as process 1
void process3()
{
    for (int i = 0; i < 100000; i++) {
        total->value++;
    }
    printf("From Process 3: counter = %d.\n", total->value);
    exit(0);
}

// Same as other processes but increments by 200,000, so that total should be 500,000 in the end
void process4()
{
    for (int i = 0; i < 200000; i++) {
        total->value++;
    }
    printf("From Process 4: counter = %d.\n", total->value);
    exit(0);
}

int main()
{
    key_t key = IPC_PRIVATE; // Use IPC_PRIVATE to get a unique key
    int shmid, pid1, pid2, pid3, pid4, status;
    char *shmadd;
    shmadd = (char *) 0;
    // Create shared memory and connect to shared mem segment
    if ((shmid = shmget(key, sizeof(shared_mem), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory
    if ((total = (shared_mem *) shmat(shmid, shmadd, 0)) == (shared_mem *) -1) {
        perror("shmat");
        exit(0);
    }

    // Initialize shared memory to 0
    total->value = 0;

    // Create processes
    // Each child only calls one process
    if ((pid1 = fork()) == 0) {
        process1();
    }

    if ((pid2 = fork()) == 0) {
        process2();
    }

    if ((pid3 = fork()) == 0) {
        process3();
    }

    if ((pid4 = fork()) == 0) {
        process4();
    }

    // Parent process waits for all children to finish, prints when they are
    for (int i = 0; i < 4; i++) {
        pid_t finished_pid = wait(&status); // Wait for a child to finish
        printf("Child with ID: %d has just exited.\n", finished_pid);
    }

    // Detach shared memory
    if (shmdt(total) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Releases shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    // End of the program
   printf("End of Program\n");

    return 0;
}