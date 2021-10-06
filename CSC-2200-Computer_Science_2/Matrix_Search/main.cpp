//
//  main.cpp
//  HW_3_2.27
//
//  Created by Nicholas Farkas on 2/17/21.
//

#include <iostream>

using namespace std;

int find(int x,int matrix[5][5]);
int sum(int a[], int size);

int main(int argc, const char * argv[])
{
    int matrix[5][5] =
    {
        {4,2,3,5,1},
        {10,11,22,12,18},
        {7,12,23,1,15},
        {10,17,26,9,20},
        {10,23,23,17,25}
    }; //Test Data
    
    cout<<find(100,matrix); //Find 20 in matrix
}

int find(int x,int matrix[][5])
{
    int n = 5;
    int row = 0, col = 0;
    
    while (col != n)
    {
        if (matrix[row][col] == x)
        {
            return 1;
        }
        if(row == n-1)
        {
            col++;
            row = 0;
        }
        else
        {
            row++;
        }
    }
    return 0;
}

int sum(int arr[], int size)
{
    int maxSum = arr[0]+arr[1];
    
    for(int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[j]+arr[i] > maxSum)
            {
                maxSum = arr[j]+arr[i];
            }
        }
    }
    return maxSum;
}
