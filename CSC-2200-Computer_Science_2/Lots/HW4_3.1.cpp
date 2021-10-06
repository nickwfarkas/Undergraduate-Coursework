//
//  main.cpp
//  HW4_3.1
//
//  Created by Nicholas Farkas on 2/23/21.
//

#include <iostream>
#include <list>
#include <ctime>

using namespace std;

void printLots(const list<int>& L,const list<int>& P);

int main(int argc, const char * argv[])
{
    list<int> L = {0,10,20,30,40,50,60,70,80,90};
    list<int> P = {0,3,4,6};
    long start;
    double duration = 0;

    start = clock();
    printLots(L, P);
    duration = (((clock()-start)/(double)CLOCKS_PER_SEC)*1000);
    
    cout<<endl<<"Running Time: "<<duration<<" seconds"<<endl;
    
    return 0;
}

void printLots(const list<int>& L,const list<int>& P)
{
    int i = 0;
    
    list<int>::const_iterator p = P.begin();

    for (list<int>::const_iterator l = L.begin(); l != L.end(); l++)
    {
        if (*p == i)
        {
            cout<<*l<<" ";
            p++;
        }
        i++;
    }
}
