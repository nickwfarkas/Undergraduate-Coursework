#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#define BUFSIZE 10
int main(void) {
    char bufin[BUFSIZE] = "empty";
    char bufout[] = "hello";
    int bytesin;
    pid_t childpid;
    #define fd
    int fd[2];
    if (pipe(fd) == -1) { /* create a pipe */
        perror("Failed to create the pipe");
        return 1;
    }
    bytesin = strlen(bufin);
    childpid = fork();
    if (childpid == -1) {
        perror("Failed to fork");

        return 1;
    }
    if (childpid > 0)
    /* child code */
        write(fd[1], bufout, strlen(bufout)+1);
    else
    /* parent code */
        bytesin = read(fd[0], bufin, BUFSIZE);
    fprintf(stderr, "[%ld]:my bufin is {%.*s}, my bufout is {%s}\n", (long)getpid(), bytesin, bufin, bufout);
    return 0;
}

