#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int id = getpid();

    printf("Before:%d\n",id);

    id = fork();

    sleep(5);
    printf("After:%d\n",getppid());

    return 0;
}