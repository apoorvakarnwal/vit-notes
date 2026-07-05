
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char buff[100];
    int shmid;
    void *shared_mem;
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    printf("Key of shared memory is: %d\n", shmid);
    shared_mem = shmat(shmid, NULL, 0);
    printf("Process at shared memory is: %p\n", shared_mem);
    printf("Data to write at shared memory is: \n");
    read(0, buff, 100);
    strcpy(shared_mem, buff);
    printf("Data shared memory is: %s", (char *)shared_mem);
    return 0;
}