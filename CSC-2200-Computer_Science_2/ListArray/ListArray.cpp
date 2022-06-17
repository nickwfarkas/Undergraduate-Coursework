
#include "ListArray.h"

template < typename DataType >
List<DataType>::List ( int maxNumber )
:maxSize(maxNumber),
size(0),
cursor(-1)
{
    dataItems = new DataType[maxSize];
}

template < typename DataType >
List<DataType>::List ( const List& source )
{
    maxSize = source.maxSize;
    size = source.size;
    cursor = source.getCursor();
    dataItems = new DataType[maxSize];
    for (int i = 0; i < size; i++)
    {
        dataItems[i] = source.dataItems[i];
    }
}
    
template < typename DataType >
List<DataType>& List<DataType>::operator= ( const List& source )
{
    if(this != &source)
    {
        if(source.maxSize > maxSize)
        {
            delete [] dataItems;
            maxSize = source.maxSize;
            dataItems = new DataType[source.maxSize];
        }
        size = source.size;
        cursor = source.getCursor();
        for(int i = 0; i < size; i++)
        {
            dataItems[i] = source.dataItems[i];
        }
    }
	return *this;
}

template < typename DataType >
List<DataType>::~List ()
{
    delete [] dataItems;
}

template < typename DataType >
void List<DataType>::insert ( const DataType& newDataItem )
	throw ( logic_error )
{
    if(isFull())
    {
        throw logic_error("List is full");
    }
    else if(isEmpty())
    {
        dataItems[0] = newDataItem;
        cursor++;
        size++;
    }
    else
    {
        for(int i = cursor; i > size; i++)
        {
            dataItems[i] = dataItems[i+1];
        }
        dataItems[cursor+1] = newDataItem;
        cursor++;
        size++;
    }
}

template < typename DataType >
void List<DataType>::remove ()
    throw ( logic_error )
{
    if(isEmpty())
    {
        throw logic_error("List is empty");
    }
    else
    {
        for(int i = size; i > cursor; i--)
        {
            dataItems[i-1] = dataItems[i];
        }
        size--;
        cursor--;
    }
}

template < typename DataType >
void List<DataType>::replace ( const DataType& newDataItem )
	throw ( logic_error )
{
    if(isEmpty())
    {
        throw logic_error("List is empty");
    }
    else
    {
        dataItems[cursor] = newDataItem;
    }
}

template < typename DataType >
void List<DataType>::clear ()
{
    cursor = -1;
    size = 0;
}

template < typename DataType >
bool List<DataType>::isEmpty () const
{
    return (size == 0);
}

template < typename DataType >
bool List<DataType>::isFull () const
{
    return (size == maxSize);
}

template < typename DataType >
void List<DataType>::gotoBeginning ()
        throw ( logic_error )
{
    if(isEmpty())
    {
        throw logic_error("List is empty");
    }
    else
    {
        cursor = 0;
    }
}

template < typename DataType >
void List<DataType>::gotoEnd ()
        throw ( logic_error )
{
    if(isEmpty())
    {
        throw logic_error("List is empty");
    }
    else
    {
        cursor = size-1;
    }
}

template < typename DataType >
bool List<DataType>::gotoNext ()
        throw ( logic_error )
{
    if(cursor == size-1)
    {
        throw logic_error("Cursor is at end of list");
        return false;
    }
    else
    {
        cursor++;
        return true;
    }
}

template < typename DataType >
bool List<DataType>::gotoPrior ()
        throw ( logic_error )
{
    if(cursor == 0)
    {
        throw logic_error("Cursor is at the beginning of list");
        return false;
    }
    else
    {
        cursor--;
        return true;
    }
}

template < typename DataType >
DataType List<DataType>::getCursor () const
        throw ( logic_error )
{
    DataType t;
    if(isEmpty())
    {
        //throw logic_error("List is empty");
    }
    else
    {
        t = dataItems[cursor];
    }
	return t;
}

#include "show3.cpp"

template < typename DataType >
void List<DataType>::moveToNth ( int n )
        throw ( logic_error )
{
    DataType t;
    if(size >= n+1)
    {
        t = dataItems[cursor];
        this->remove();
        cursor = n;
        this->insert(t);
    }
    else
    {
        throw logic_error("Nth term is out of range");
    }
}

template < typename DataType >
bool List<DataType>::find ( const DataType& searchDataItem )
        throw ( logic_error )
{
    if(isEmpty())
    {
        throw logic_error("List is empty");
    }
    else
    {
        for(cursor = 0; cursor < size; cursor++)
        {
            if(dataItems[cursor] == searchDataItem)
            {
                return true;
            }
        }
        return false;
    }
}
