//
//  main.cpp
//  HW_5_4.37
//
//  Created by Nicholas Farkas on 3/29/21.
//

#include <iostream>

using namespace std;

typedef struct treeNode
{
    int element;
    struct treeNode * left;
    struct treeNode * right;
}NODE;

void printInBetween(NODE * node, int k1, int k2);

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

void printInBetween(NODE * node, int k1, int k2)
{
    if (node)
    {
        if (k1 < node->element)
        {
            printInBetween(node->left, k1, k2);
        }
        else if (node->element <= k2)
        {
            printInBetween(node->right, k1, k2);
        }
        else if (k1 <= node->element && k2 >= node->element)
        {
            cout<<node->element<<endl;
        }
    }
    else
    {
        cout<<"Empty"<<endl;
    }
}
