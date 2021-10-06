//
//  main.cpp
//  HW4_3.4
//
//  Created by Nicholas Farkas on 2/23/21.
//

#include <iostream>
#include <list>

using namespace std;

list<int> findIntersection(const list<int>* L1,const list<int>* L2);

int main(int argc, const char * argv[])
{
    list<int> L1 = {0,10,20,30,40,50,60,70,80,90};
    list<int> L2 = {0,5,10,15,20,25,30,35,40,45};
    
    findIntersection(&L1, &L2);
    
    return 0;
}

list<int> findIntersection(const list<int>* L1,const list<int>* L2)
{
    list<int> intersection;
    const list<int>* max;
    const list<int>* min;

    if (L1->size() > L2->size())
    {
        max = L1;
        min = L2;
    }
    else
    {
        max = L2;
        min = L1;
    }
    
    list<int>::const_iterator min_iter = min->begin();
    list<int>::const_iterator max_iter = max->begin();
    
    while (min_iter != min->end() && max_iter != max->end())
    {
        if (*max_iter == *min_iter)
        {
            cout<<*max_iter<<endl;
            intersection.push_back(*max_iter);
            min_iter++;
            
        }
        else if (*max_iter > *min_iter)
        {
            min_iter++;
        }
        else
        {
            max_iter++;
        }
    }
    
    return intersection;
}

