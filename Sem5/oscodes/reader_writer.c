#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

int read_count = 0;
sem_t resourse, read_count_access;
void *reader(void *args)
{
    sem_wait(&read_count_access);
    read_count++;
    if (read_count == 1)
    {
        sem_wait(&resourse);
    }
    sem_post(&read_count_access);

    printf("reader %d is reading\n", *((int *)args));

    sem_wait(&read_count_access);
    read_count--;
    if (read_count == 0)
    {
        sem_post(&resourse);
    }
    sem_post(&read_count_access);

    return NULL;
}

void *writer(void *args)
{
    sem_wait(&resourse);
    printf("writer %d is writing\n", *((int *)args));
    sem_post(&resourse);
    return NULL;
}

int main()
{
    pthread_t r[5], w[2];
    int reader_id[5], writer_id[2];

    sem_init(&resourse, 0, 1);
    sem_init(&read_count_access, 0, 1);
    for (int i = 0; i < 5; i++)
    {
        reader_id[i] = i;
        pthread_create(&r[i], NULL, reader, &reader_id[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        writer_id[i] = i;
        pthread_create(&w[i], NULL, writer, &writer_id[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(r[i], NULL);
    }
    for (int i = 0; i < 2; i++)
    {
        pthread_join(w[i], NULL);
    }

    sem_destroy(&resourse);
    sem_destroy(&read_count_access);

    return 0;
}