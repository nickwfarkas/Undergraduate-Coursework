#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t M;
pthread_cond_t C;

void * w();

int main()
{
    int temp = 0;
    pthread_t threads[10];
    pthread_mutex_init(&M, 0);
    pthread_cond_init(&C, 0);

    for (int i = 0; i < 10; i++)
    {
        printf("Thread %d\n", i);
        temp = pthread_create(&threads[i], 0, w, (void *)i);
    }

    pthread_mutex_lock(&M);
    pthread_cond_broadcast(&C);
    pthread_mutex_unlock(&M);

    for (int i = 0; i < 10; i++)
    {
        pthread_join(threads[i], 0);
    }

    return 0;
}

void * w()
{
    pthread_mutex_lock(&M);
    pthread_cond_wait(&C, &M);
    pthread_mutex_unlock(&M);
    pthread_exit(0);
}
