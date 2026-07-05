#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define N 5
sem_t fork[N];

void *philosopher(void *args)
{
    int id = *((int *)args);
    int left = id;
    int right = (left + 1) % N;
    while (1)
    {
        printf("Philosopher %d is thinking", id);
        sem_wait(&fork[left]);
        sem_wait(&fork[right]);

        printf("Philosopher %d is eating", id);

        sem_post(&fork[left]);
        sem_post(&fork[right]);
    }
    return NULL;
}
int main()
{
    int philosopher_id[N];
    pthread_t philosophers[N];

    for (int i = 0; i < N; i++)
    {
        sem_init(&fork[i], 0, 1);
        philosopher_id[i] = i + 1;
    }

    for (int i = 0; i < N; i++)
    {
        pthread_create(&philosophers, NULL, philosopher, &philosopher_id[i]);
    }
    for (int i = 0; i < N; i++)
    {
        pthread_join(philosophers, NULL);
    }

    for (int i = 0; i < N; i++)
    {
        sem_destroy(&fork[i]);
    }
    return 0;
}