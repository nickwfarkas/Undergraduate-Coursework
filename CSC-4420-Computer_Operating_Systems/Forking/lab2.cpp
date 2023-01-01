//
//  main.cpp
//  Lab_2
//
//  Created by Nicholas Farkas
//

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int argc, const char * argv[])
{
    pid_t fork1 = fork();
    pid_t fork2 = fork();

    if (fork1 == 0 && fork2 > 0)
    {
        wait(0);
        wait(0);
    }
    else if (fork1 > 0 && fork2 > 0)
    {
        sleep(10);
        wait(0);
    }
    else
    {
        sleep(10);
    }
    
    return 0;
}
