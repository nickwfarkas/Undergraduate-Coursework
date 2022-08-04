#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main() 
{
    int time = 0;
    int id = fork();

	if (id == 0) 
    {
		while(true) 
        {
			++time;
            sleep(1);
		}
		exit(0);
	}
	else 
    {
		wait(0);
		cout << "Time elapsed: " << time <<endl;
	}

	return 0;
}