#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>

void *print_message_function( void *ptr );

main() {
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2;
    
    iret1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1);
    iret2 = pthread_create(&thread2, NULL, print_message_function, (void*) message2);
    
    void* resp1;
    void* resp2;
    
    pthread_join(thread1, &resp1);
    pthread_join(thread2, &resp2);
    
    printf("Thread 1: %d\n", (int)resp1);
    printf("Thread 2: %d\n", (int)resp2);
    
    return(0);
}

void *print_message_function( void *ptr ) {
    char *message;
    message = (char *) ptr;
    printf("%s \n", message);
}
