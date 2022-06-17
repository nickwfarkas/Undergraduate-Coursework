
#include "QueueLinked.h"

template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
// Creates a queue node containing data item nodeDataItem and next
// pointer nextPtr.
{
    dataItem = nodeData;
    next = nextPtr;
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber)
// Creates an empty queue. Parameter is provided for compatability
// with the array implementation and is ignored.
{
    front = NULL;
    back = NULL;
}

template <typename DataType>
QueueLinked<DataType>::~QueueLinked()
// Frees the memory used by a queue.
{
    QueueNode *temp = front;
    QueueNode *current = temp;
    
    while(temp != NULL)
    {
        temp = temp->next;
        current = temp;
        free(current);
    }
}

template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
// Inserts newDataItem at the rear of a queue.
{
    if(isFull())
    {
        throw("Queue is full");
    }
    else
    {
        QueueNode *temp = new QueueNode(newDataItem,NULL);
        
        if(front != NULL)
        {
            back->next = temp;
            back = temp;
        }
        else
        {
            front = temp;
            back = temp;
        }

    }
}

template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error)
// Removes the least recently (front) element from a queue and
// returns it.
{
    if(isEmpty())
    {
        throw logic_error("Queue is empty");
    }
    
    DataType temp;
    
    temp = front->dataItem;
    front = front->next;

    return temp;
}

template <typename DataType>
void QueueLinked<DataType>::clear()
// Removes all the elements from a queue.
{
    QueueNode *temp = front;
    QueueNode *current = temp;
    
    while(temp != NULL)
    {
        temp = temp->next;
        free(current);
        current = temp;
    }

    front = NULL;
    back = NULL;
}

template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const
// Returns true if a queue is empty. Otherwise, returns false.
{
	return (front == NULL);
}

template <typename DataType>
bool QueueLinked<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void QueueLinked<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
//  Enqueues newDataItem at the front of the queue --
//  deque behavior -- instead of at the back as would normally happen.
{
    if(isFull())
    {
        throw("Queue is full");
    }
    else
    {
        QueueNode * temp = new QueueNode(newDataItem, front);
        
        if(front == NULL)
        {
            back = front;
        }

        front = temp;
    }
}

template <typename DataType>
DataType QueueLinked<DataType>::getRear() throw (logic_error)
//  Removes and returns the dataItem at the rear of the queue --
//  deque behavior -- instead of at the head as would normally happen.
{
    DataType temp;
    
    if(isEmpty())
    {
        throw("The queue is empty");
    }
    else
    {
        temp = back->dataItem;

        if(front == back)
        {
            front = NULL;
            delete back;
        }
        else
        {
            QueueNode *current = front;
          
            while(current->next != back)
            {
                current=current->next;
            }

          delete back;
          back = current;
        }
    }
    return temp;
}

template <typename DataType>
int QueueLinked<DataType>::getLength() const
//  Calculates and returns the length of the queue.
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        int count = 0;
        QueueNode *temp = front;
        
        while(temp != NULL)
        {
          temp = temp->next;
          count++;
        }
        
        return count;
    }
}

template <typename DataType>
void QueueLinked<DataType>::showStructure() const
{
    QueueNode *p;   // Iterates through the queue

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != 0 ; p = p->next )
	{
	    if( p == front ) 
	    {
		cout << '[' << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}
