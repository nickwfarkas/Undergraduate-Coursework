#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>

int main()
{
    FILE *file;

    char s1[100];
    char s2[100];

    sprintf(s1, "pstree -s -p %d", getpid());

    file = popen(s1, "r");

    fgets(s2, 100, file);

    printf("%s\n", s2);

    pclose(file);
}