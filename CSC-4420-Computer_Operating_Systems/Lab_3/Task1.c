#include<pthread.h>
#include<stdio.h>

#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
    long tid;
    tid = (long)threadid;
    printf("Hello World! It's me, thread #%ld!\n", tid); 
    pthread_exit(NULL);
}
int main (int argc, char *argv[])
{
    int temp1 = 0;
    int temp2 = 0;
    
    pthread_t threads[NUM_THREADS];
    
    long t;
    
    for(t=0; t<NUM_THREADS; t++){
        printf("In main: creating thread %ld\n", t);
        
        temp1 = pthread_create(&threads[t],NULL,PrintHello,(void*)t);
        
        if(temp1 != 0)
        {
        	printf("Error code: %d",temp1);
        }
        
        temp2 = pthread_join(threads[t],NULL);
        
        if(temp2 != 0)
        {
        	printf("Error code: %d",temp2);
        }
    }
    pthread_exit(NULL);
}
