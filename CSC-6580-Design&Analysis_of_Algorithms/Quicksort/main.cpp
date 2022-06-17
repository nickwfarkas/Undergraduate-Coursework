//
//  main.cpp
//  Assignment2
//
//  Created by Nicholas Farkas on 3/2/22.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
void print(string arr[], int arraySize);
void quickSort(string arr[], int low, int high);
int partition (string arr[], int low, int high);
double findMedian(vector<int> arr, int n);
void Largest(int arr[], int low, int high, int k, int n);
int findRandomPivot(int arr[], int start, int end);
int findPivot(int arr[], int start, int end);

int main(){
    // 8

    int outWordsArrSize = 0;
    string sentence = "This is a sort tool on words";
    string * stringArray = createWordsArray(sentence, outWordsArrSize);

    quickSort(stringArray,0,outWordsArrSize-1);

    print(stringArray, outWordsArrSize);
    cout<<endl;

    // 9

    int arr[] = { 2, 3, 10, 12, 11, 1, 5, 4, 8, 9, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"The "<<n<<" largest elements are: ";

    largest(arr, 0, n-1, 5, n);

    cout<<endl;

    // 10

    vector<int> a = { 2, 5, 6, 8, 9, 10, 7 };

    cout<<"Median: "<<findMedian(a, a.size())<<endl<<endl;

    
    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize)
{
    int wordStartIndex = 0;

    do
    {
        outWordsArrSize++;
        wordStartIndex++;
    }while((wordStartIndex = sentence.find(" ",wordStartIndex)) != string :: npos);
    
    string *strArr = new string[outWordsArrSize];
    int strArrIndex = 0;
    wordStartIndex = 0;
    
    while(sentence.find(" ",wordStartIndex) != string :: npos)
    {
        int wordLength = sentence.find(" ",wordStartIndex) - wordStartIndex;
        string word = sentence.substr(wordStartIndex,wordLength);
        strArr[strArrIndex++] = word;
        wordStartIndex = sentence.find(" ",wordStartIndex) + 1;
    }
    
    strArr[strArrIndex] = sentence.substr(wordStartIndex,sentence.length() - wordStartIndex);

    return strArr;
}

void quickSort(string arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition (string arr[], int low, int high)
{
    string pivot = arr[high];
    char pivotElement[pivot.length() + 1];
    int i = (low - 1);
    
    strcpy(pivotElement,pivot.c_str());
    
    for(int j = low; j <= high - 1; j++)
    {
        char currentElement[arr[j].length() + 1];
        
        strcpy(currentElement,arr[j].c_str());
        
        if(strcmp(currentElement , pivotElement) < 0)
        {
            i++;
            arr[i].swap(arr[j]);
        }
    }
    
    arr[i+1].swap(arr[high]);
    
    return (i + 1);
}

void print(string arr[], int arraySize)
{
    for(int i = 0 ; i < arraySize; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}
 
double findMedian(vector<int> arr, int n)
{
    if(n % 2 == 0)
    {
        nth_element(arr.begin(), arr.begin() + n / 2, arr.end());
  
        nth_element(arr.begin(), arr.begin() + (n - 1) / 2, arr.end());
  
        return (double)(arr[(n - 1) / 2]+ arr[n / 2])/ 2.0;
    }
    else
    {
        nth_element(arr.begin(), arr.begin() + n / 2,arr.end());
  
        return (double)arr[n / 2];
    }
}

int findPivot(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pIndex = start;

    for(int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);
            
            pIndex++;
        }
    }
    
    swap(arr[pIndex], arr[end]);

    return pIndex;
}

int findRandomPivot(int arr[], int start, int end)
{
    int n = end - start + 1;
    int pivotInd = random() % n;
    
    swap(arr[end],arr[start+pivotInd]);
    
    int pivot = arr[end];
    pivotInd = start;

    for(int i = start; i < end; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[i], arr[pivotInd]);
            
            pivotInd++;
        }
    }
    
    swap(arr[pivotInd], arr[end]);

    return pivotInd;
}

void largest(int arr[], int low, int high, int k, int n)
{
    int pivotIndex = findRandomPivot(arr, low, high);
    
    if(k == pivotIndex)
    {
        for (int i = (n - pivotIndex); i < n; i++)
        {
            cout << arr[i] << " ";
        }
        
        cout<<endl;
    }
    else if(k < pivotIndex)
    {
        largest(arr, low, pivotIndex - 1, k, n);
    }
    else if(k > pivotIndex)
    {
        largest(arr, pivotIndex + 1, high, k, n);
    }
}
