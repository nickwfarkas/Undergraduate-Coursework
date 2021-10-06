//Nicholas Farkas

#include "StackLinked.h"

template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& newDataItem,
					  StackLinked<DataType>::StackNode* nextPtr)

// Creates a stack node containing item newDataItem and next pointer
// nextPtr.

    : dataItem(newDataItem), next(nextPtr)
{
}

template <typename DataType>
StackLinked<DataType>::StackLinked (int maxNumber)
// Creates an empty stack. The parameter maxNumber is provided for 
// compatability with the array implementation and is ignored.
{
    top = NULL;
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
// Copy constructor for linked stack
{
    top = NULL;
    StackNode temp = other.top;
    
    while (temp != NULL)
    {
        top = new StackNode(temp.dataItem,top);
        temp = temp.next;
    }
}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
// Overloaded assignment operator for the StackLinked class.
// Because this function returns a StackLinked object reference,
// it allows chained assignment (e.g., stack1 = stack2 = stack3).
{
    if(this != &other)
    {
        return *this;
    }
    
    top = NULL;
    StackNode temp = other.top;
    
    while (temp != NULL)
    {
        top = new StackNode(temp.dataItem,top);
        temp = temp.next;
    }
    return *this;
}

template <typename DataType>
StackLinked<DataType>::~StackLinked()
// Destructor. Frees the memory used by a stack.
{
	clear();
}

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
// Inserts newDataItem onto the top of a stack.
{
    if(isFull())
    {
        throw logic_error("List is full");
    }
    top = new StackNode(newDataItem,top);
}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
// Removes the topmost item from a stack and returns it.
{
    if(isEmpty())
    {
        throw logic_error("Lisy is empty");
    }
    DataType temp = top->dataItem;
    top = top->next;
    return temp;
}

template <typename DataType>
void StackLinked<DataType>::clear()
// Removes all the data items from a stack.
{
    StackNode* t;
    while(top != NULL)
    {
        t = top;
        top = top->next;
        delete t;
    }
}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
// Returns true if a stack is empty. Otherwise, returns false.
{
    return (top == NULL);
}

template <typename DataType>
bool StackLinked<DataType>::isFull() const
// Returns true if a stack is full. Otherwise, returns false. 
{
	return false;
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const
{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}
