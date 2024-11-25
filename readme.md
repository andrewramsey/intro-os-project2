READ ME
Author: Andrew Ramsey 
OU 4x4: rams0040
OU ID: 113546093
VM Username: cs105

Intro to Operating Systems Programming Assignment 2 (Semaphores)

This program uses shared memory to run 4 child processes that increment concurrently to a shared value without synchronization. The processes are meant to increment from 1 to 100,000, then to 200,000, to 300,000, and finally to 500,000. It prints the value after each process finishes and prints when a child process exits. It is a modified version of Project 1, which uses semaphores so that the final shared value output will be 1,100,000. Increments to the shared value will not be lost, but processes aside from the final one can still have a random value (that is not 100,000 etc.).

The title page is included on the first page on the project2-report.pdf

To run project2.c: 
Open the directory of Linux it is in with "cd directory-name"
Run "gcc project2.c -o project2", this compiles it (another name aside from project2 can be used)
After compiling, run "./project2" which executes it (that other name could be used here)
To read the contents, you can use text editors such as nano, vim, or emacs
To give an example of opening the file, you can run nano project2.c and this opens the file in nano



