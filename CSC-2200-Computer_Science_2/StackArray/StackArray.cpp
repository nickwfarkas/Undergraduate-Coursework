
#include "StackArray.h"

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber)
// Creates an empty stack. 
{
    dataItems = new DataType[maxNumber];
    maxSize = maxNumber;
    top = -1;
}

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
// Copy constructor for linked stack
{
    maxSize = other.maxSize;
    top = other.top;
    dataItems = new DataType[maxSize];
    for (int i = 0; i < maxSize; i++)
    {
        dataItems[i] = other.dataItems[i];
    }
}

template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)
{
    maxSize = other.maxSize;
    top = other.top;
    dataItems = new DataType[maxSize];
    for (int i = 0; i < maxSize; i++)
    {
        dataItems[i] = other.dataItems[i];
    }
    return *this;
}

template <typename DataType>
StackArray<DataType>::~StackArray()
// Frees the memory used by a stack.
{
    delete [] dataItems;
    top = -1;
    maxSize = 0;
}

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
// Inserts newDataItem onto the top of a stack.
{
    if(isFull())
    {
        throw("List is full");
    }
    else
    {
        top++;
        dataItems[top] = newDataItem;
    }
}

template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
// Removes the topmost data item from a stack and returns it.
{
	if(isEmpty())
    {
        throw("List is empty");
    }
    else
    {
        top--;
        return dataItems[top+1];
    }
}

template <typename DataType>
void StackArray<DataType>::clear()
// Removes all the data items from a stack.
{
    top = -1;
}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const
// Returns true if a stack is empty. Otherwise, returns false.
{
	return (top == -1);
}

template <typename DataType>
bool StackArray<DataType>::isFull() const
// Returns true if a stack is full. Otherwise, returns false.
{
	return ((top + 1) == maxSize);
}

template <typename DataType>
void StackArray<DataType>::showStructure() const 

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}
