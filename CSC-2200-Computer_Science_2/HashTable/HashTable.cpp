
#include "HashTable.h"
#include "show10.cpp"

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize)
// initial all the data members of the hashtable.
{
    tableSize = initTableSize;
    dataTable = new BSTree<DataType, KeyType>[initTableSize];
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& other)
// copy constructor: deep copy all the data members of "other" to "this"
{
    if (this != &other)
    {
        *this = other;
    }
}

template <typename DataType, typename KeyType>
HashTable<DataType,KeyType>& HashTable<DataType, KeyType>::operator=(const HashTable& other)
// assignment operator: delete the remaning object. Deep copy "other" object to this.
{
    if(this == &other)
    {
        return *this;
    }
    if(!isEmpty())
    {
        clear();
    }
    copyTable(other);
    return *this;
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable()
// destructor: free all the memmory used by the hashtable
{
    clear();
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem)
// insert the newDataItem to the hashtable
// first get the "hash" number of the newDataItem (remember that DataType has the function hash - read the file test10)
// find the index of the array that the newDataItem belongs to (hashnumber % tableSize)
// use the insert function of the BStree at that index to insert the newDataItem
{
    dataTable[newDataItem.hash(newDataItem)%tableSize].insert(newDataItem);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey)
// same as insert, but use the remove function of the BStree the newDateItem at that index
{
    DataType temp;
    return dataTable[temp.hash(deleteKey)%tableSize].remove(deleteKey);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const
// same as insert, but use the retrieve function of the BStree the newDateItem at that index
{
    return dataTable[returnItem.hash(searchKey)%tableSize].retrieve(searchKey,returnItem);
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear()
// for all BStree in the array, use the clear function of the BStree class.
{
    for (int i = 0; i < tableSize; i++)
    {
        dataTable[i].clear();
    }
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const
// hashtable is empty if all the BStree in it is empty.
{
    for (int i = 0; i < tableSize; i++)
    {
        if (!dataTable[i].isEmpty())
        {
            return false;
        }
    }
    return true;
}

template <typename DataType, typename KeyType>
double HashTable<DataType, KeyType>::standardDeviation() const
// 1.Work out the Mean (the simple average of the numbers)
// 2.Then for each number: subtract the Mean and square the result.
// 3.Then work out the mean of those squared differences.
// 4.Take the square root of that and we are done!
// example : https://www.mathsisfun.com/data/standard-deviation-formulas.html
{
    int total = 0;
    double sum = 0.0;
    int size;
    double average;

    for (int i = 0; i < tableSize; i++)
    {
        total += dataTable[i].getCount();
    }

    average = total/tableSize;
    
    for (int i = 0; i < tableSize; i++)
    {
        size = dataTable[i].getCount();
        sum += ((size - average) * (size - average));
    }

    return sqrt(sum/(tableSize-1));
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source)
// helper function for the copy constructor and assignment operator.
// no recursion needed. Just need a for loop.
// you might not need this function if you implemented the copy constructor and assignment operator correctly already.
{
    tableSize = source.tableSize;
    dataTable(tableSize);
    for (int i = 0; i < tableSize; i++)
    {
        dataTable[i] = source.dataTable[i];
    }
}
