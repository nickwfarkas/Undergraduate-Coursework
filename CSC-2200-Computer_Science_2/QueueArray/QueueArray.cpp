
#include "QueueArray.h"

template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber)
: maxSize(maxNumber), front(-1), back(-1)
// Creates an empty queue. Allocates enough memory for maxNumber
// data items (defaults to MAX_QUEUE_SIZE in class declaration).
{
    dataItems = new DataType[maxNumber];
}

template <typename DataType>
QueueArray<DataType>::~QueueArray()
// Frees the memory used by a queue.
{
    delete[] dataItems;
}


template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
// Inserts newDataItem at the rear of a queue.
{
    if(isFull())
    {
        throw logic_error("Queue is full");
    }

    back = (++back)%maxSize;
    dataItems[back] = newDataItem;
    
    if(front == -1)
    {
        front = 0;
    }
}

template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error)
// Removes the least recently added (front) data item from a queue
// and returns it.

{
    int temp = front;
    
    if(isEmpty())
    {
        throw logic_error("Queue is empty");
    }
    else if(front == back)
    {
        front = -1;
        back  = -1;
    }
    else
    {
        front = (++front)%maxSize;
    }

    return dataItems[temp];
}

template <typename DataType>
void QueueArray<DataType>::clear()

// Removes all the data items from a queue.
{
    front = -1;
    back = -1;
}

template <typename DataType>
bool QueueArray<DataType>::isEmpty() const
{
	return (front == -1);
}

template <typename DataType>
bool QueueArray<DataType>::isFull() const
{
	return front == (back + 1)%maxSize;
}

template <typename DataType>
void QueueArray<DataType>::putFront(const DataType& newDataItem) throw (logic_error)

//  Enqueues newDataItem at the front of the queue --
//  deque behavior -- instead of at the back as would normally happen.
{
    if(isFull())
    {
        throw logic_error("Queue is full");
    }

    --front;
    
    if(front < 0)
    {
        front = maxSize - 1;
    }
    
    dataItems[front] = newDataItem;
}

template <typename DataType>
DataType QueueArray<DataType>::getRear() throw (logic_error)

//  Removes and returns the dataItem at the rear of the queue --
//  deque behavior -- instead of at the head as would normally happen.
{
    int temp = back;
    
    if(isEmpty())
    {
       throw logic_error("Queue is empty");
    }
    
    --back;
    if (back == front-1)
    {
        back = -1;
        front = -1;
    }
    else if (back < 0)
    {
       back = maxSize - 1;
    }

    return dataItems[temp];
}

template <typename DataType>
int QueueArray<DataType>::getLength() const
//  Calculates and returns the length of the queue.
{
    if(isEmpty())
    {
        return 0;
    }
    else if(front > back)
    {
        return (maxSize - front) + (back + 1);
        
    }
    else
    {
        return (back - front) + 1;
    }
}

//--------------------------------------------------------------------

template <typename DataType>
void QueueArray<DataType>::showStructure() const 
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if ( front == -1 )
       cout << "Empty queue" << endl;
    else
    {
       cout << "Front = " << front << "  Back = " << back << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       if ( back >= front )
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) && ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       else
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) || ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       cout << endl;
    }
}
