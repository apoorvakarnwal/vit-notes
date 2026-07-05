#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork(); // Create a new process by forking

    if (pid > 0)
    { // Parent process
        printf("Parent Process: PID = %d %d\n", getpid(), pid);
    }
    else if (pid == 0)
    { // Child process
        printf("Child Process: PID = %d, Parent PID = %d  %d\n", getpid(), getppid(), pid);
    }
    else
    { // Fork failed
        perror("Fork failed");
        exit(1);
    }

    return 0;
}
