//
//  main.cpp
//  Assignment4
//
//  Created by Nicholas Farkas on 4/6/22.
//

#include <iostream>
using namespace std;

void contiguousSubsequence(int n, int arr[])
{
   int m = arr[0];
   int currentMax = arr[0];
 
   for (int i = 0; i < n; i++)
   {
       currentMax = max(arr[i], currentMax + arr[i]);
       m = max(m, currentMax);
   }
   cout<<"The contiguous subsequence of maximum sum: "<<m<<endl;
}

void palindromicSubSequence(string org)
{
    string rev = "";
    for (int i = org.length(); i > 0; i--)
    {
        rev+=org[i];
    }

    int M[org.length()+1][rev.length()+1];
 
    for (int i = 0; i <= org.length(); i++)
    {
        for (int j = 0; j <= rev.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                M[i][j] = 0;
            }
            else if (org[i-1] == rev[j-1])
            {
                M[i][j] = M[i-1][j-1]+1;
            }
            else
            {
                M[i][j] = max(M[i-1][j], M[i][j-1]);
            }
        }
    }
    
    string temp(M[org.length()][rev.length()], ' ');
    int orgLength = org.length();
    int revLength = rev.length();
    int i = M[org.length()][rev.length()];
    
    do
    {
        if (org[orgLength-1] == rev[revLength-1])
        {
            temp[i-1] = org[orgLength-1];
            orgLength--;
            revLength--;
            i--;
        }
        else if (M[orgLength-1][revLength] > M[orgLength][revLength-1])
        {
            orgLength--;
        }
        else
        {
            revLength--;
        }
    }while (orgLength > 0 && revLength > 0);
 
    cout<<"Longest Palindromic Subsequence: "<<temp<<endl;
    cout<<"Longest Palindromic Subsequence Length: "<<temp.length()<<endl;
}

int main(int argc, const char * argv[])
{
    int test[] = {5,15,-30,10,-5,40,10};
    contiguousSubsequence(7,test);
    palindromicSubSequence("ACGTGTCAAAATCG");
    return 0;
}


