#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int pipefds[2];                           // Array for pipe file descriptors
    char write_msg[20] = "Hello from Child!"; // Message to be sent from child to parent
    char read_msg[20];                        // Buffer for the message read by parent

    // Create a pipe
    if (pipe(pipefds) == -1)
    {
        perror("Pipe failed");
        exit(1);
    }

    pid_t pid = fork(); // Fork a new process

    if (pid > 0)
    {                                                 // Parent process
        close(pipefds[1]);                            // Parent closes the write end of the pipe
        read(pipefds[0], read_msg, sizeof(read_msg)); // Parent reads the message from the pipe
        printf("Parent Process (PID=%d): Received message: %s\n", getpid(), read_msg);
        wait(NULL); // Parent waits for the child to finish
    }
    else if (pid == 0)
    {                                                        // Child process
        close(pipefds[0]);                                   // Child closes the read end of the pipe
        write(pipefds[1], write_msg, strlen(write_msg) + 1); // Child writes the message to the pipe
        printf("Child Process (PID=%d): Sent message to parent.\n", getpid());
        exit(0); // Child exits
    }
    else
    { // Fork failed
        perror("Fork failed");
        exit(1);
    }

    return 0;
}
