#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

using namespace std;

int main()
{
    int time = 0;
    int id = fork();

    if(id == 0)
    {
        while(true)
        {
            cout<<++time<<endl;
            sleep(1);
        }
    }
    else if(id > 0) 
    {
        sleep(15);
        kill(id, SIGTERM);
        cout<<"Killed"<<endl;
    } 
    return 0;
}