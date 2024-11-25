READ ME
Author: Andrew Ramsey 
OU 4x4: rams0040
OU ID: 113546093
VM Username: cs105

Intro to Operating Systems Programming Assignment 1 (Shared Memory)

This program uses shared memory to run 4 child processes that increment concurrently to a shared value without synchronization. The processes are meant to increment from 1 to 100,000, then to 200,000, to 300,000, and finally to 500,000. It prints the value after each process finishes and prints when a child process exits. The shared memory is unpredictable though, so the values change.

The title page is included on the first page on the project1-report.pdf

To run project1.c: 
Open the directory of Linux it is in with "cd directory-name"
Run "gcc project1.c -o project1", this compiles it
After compiling, run "./project1" which executes it
To read the contents, you can use text editors such as nano, vim, or emacs
To give an example of opening the file, you can run nano project1.c and this opens the file in nano


project1.c written in nano

