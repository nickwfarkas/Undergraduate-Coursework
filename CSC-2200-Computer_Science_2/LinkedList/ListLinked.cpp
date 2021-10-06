
#include "ListLinked.h"

// ListNode member functions

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr)
    :dataItem(nodeData),next(nextPtr)
{
	
}

// List member functions

template <typename DataType>
List<DataType>::List(int ignored)
    :head(0),
     cursor(0)
{
}

template <typename DataType>
List<DataType>::List(const List& other)
{
    operator=(other);
}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other)
{
    if(this != &other)
    {
        clear();
        ListNode* otherPtr = other.head;
        ListNode* cursorHolder = 0;
        while(otherPtr != 0)
        {
            insert(otherPtr->dataItem);
            if(otherPtr == other.cursor)
            {
                cursorHolder = otherPtr;
            }
            otherPtr = otherPtr->next;
            
        }
        cursor = cursorHolder;
    }
    return *this;
}

template <typename DataType>
List<DataType>::~List()
{
    clear();
}

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)
{
    if (isEmpty())
    {
        head = new ListNode(newDataItem, 0);
        cursor = head;
    }
    else
    {
        cursor->next = new ListNode(newDataItem, cursor->next);
        cursor = cursor->next;
    }
    
}

template <typename DataType>
void List<DataType>::remove() throw (logic_error)
{
   ListNode* Temp;
   if (isEmpty())
   {
       cout<<"List is empty."<<endl;
   }
   else if (cursor == head)
   {
       Temp = head;
       head = head->next;
       gotoNext();
       delete Temp;
   }
   else
   {
       ListNode* h;
       Temp = cursor;
       h = head;
       while (h->next != cursor)
       {
           h = h->next;
       }
       if (cursor->next != NULL)
       {
           cursor = cursor->next;
       }
       else
       {
           cursor = head;
       }
       h->next = Temp->next;
       delete Temp;
       delete h;
   }
}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)
{
    if (isEmpty())
    {
        throw logic_error("list is empty.");
    }
    else if (head != NULL)
    {
        cursor->dataItem = newDataItem;
    }
}

template <typename DataType>
void List<DataType>::clear()
{
    if (isEmpty())
    {
        cout << "List is empty!" << endl;
    }
    else
    {
        
        
    }
}

template <typename DataType>
bool List<DataType>::isEmpty() const
{
	return (head == 0);
}

template <typename DataType>
bool List<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error)
{
    cursor = head;
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error)
{
    while (cursor->next != 0)
    {
        cursor = cursor->next;
    }
}

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)
{
   if(cursor->next!= 0)
   {
       cursor = cursor->next;
       return true;
   }
   else
   {
       return false;
   }
}

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)
{
    if (cursor != head && head != NULL)
    {
        ListNode *temp = head;
        while (temp->next != cursor)
        {
            temp = temp->next;
        }
        cursor = temp;
        return true;
    }
    else
    {
        return false;
    }
}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error)
{
    if (!isEmpty())
    {
        return cursor->dataItem;
    }
    else
    {
        throw logic_error("List is empty");
    }
}

template <typename DataType>
void List<DataType>::moveToBeginning() throw (logic_error)
{
    if (cursor != head && head != NULL)
    {
        ListNode* temp = head;
        while (temp->next != cursor)
        {
            temp = temp->next;
        }
        temp->next = cursor->next;
        cursor->next = head;
        head = cursor;
    }
}

template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error)
{
    if (isEmpty())
    {
        head = new ListNode(newDataItem, 0);
        cursor = head;
    }
    else
    {
        if (cursor == head)
        {
            ListNode *temp = new ListNode(newDataItem, head);
            head = temp;
            cursor = temp;
        }
        else
        {
            gotoPrior();
            insert(newDataItem);
        }
    }
}

#include "show5.cpp"

