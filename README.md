# Problem 1 
A multi threaded program that calculates various statistical values.
## statistics_multi_thread.c
Write a multithreaded program that calculates various statistical values for a list of
numbers. This program will be passed a series of numbers on the command line and will
then create three separate worker threads. One thread will determine the average of the
numbers, the second will determine the maximum value, and the third will determine the
minimum value.
The variables representing the average, minimum, and maximum values will be stored
globally. The worker threads will set these values, and the parent thread will output the
values once the workers have exited.
## Description
Multithreading is the ability of an operating system process to manage its use by more than one user at a time and to even manage multiple requests by the same user without having to have multiple copies of the programming running in the computer. So, in this problem I have to create three different threads. I initialized an array of dynamic size as set by user and then user need to enter the elements. I created three variables for storing minimum, maximum and average value in the global scope. In main function, array is stored and passed to different threads for calculating the needs. The thread function then calculates the values and to the variables that are in global scope. After this, main function prints out those values to console from the global variables. Our solution use concepts of threads from operating system.
### Test Cases
```
No. of elements: 7
Values: [90, 81, 78, 95, 79, 72, 85]
```
```
No. of elements: 2
Values: [-4, 110] 
```
```
No of elements: 15
Values: [-10, -7, -1, 0, 67, 111, 9, 7, -19, 87, 27, 225, 2826, 82, 29] 
```
# Problem 2
A program on concepts of inter-process communication using ordinary pipes.
## *case_exchange.c
Design a program using concepts of inter-process communication ordinary pipes in
which one process sends a string message to a second process, and the second process
reverses the case of each character in the message and sends it back to the first process.
For example, if the first process sends the message Hi There, the second process will
return hI tHERE. This will require using two pipes, one for sending the original message
from the first to the second process and the other for sending the modified message from 
the second to the first process. You can write this program using either UNIX or
Windows pipes.
## Description
Conceptually, a pipe is a connection between two processes, such that the standard output from one process becomes the standard input of the other process. In UNIX Operating System, Pipes are useful for communication between related processes (inter-process communication). In this problem we need to declare two different pipes to communicate between two different process i.e. parent process and child process. Mainly our program use pipes and processes system calls for implementing the solution.
'''
int pipe(int fds[2]);
Parameters :
fd[0] will be the fd(file descriptor) for the 
read end of pipe.
fd[1] will be the fd for the write end of pipe.
Returns : 0 on Success.
-1 on error.
```
### Test Cases
```
Input String: 12…a..546L;
Expected String: 12…A..546l;
```
```
Input String: Hi There 
Expected Output: hI tHERE
```
```
Input String: 123H Aga#$RWAl
Expected Output: 123h aGA#rwaL
```
