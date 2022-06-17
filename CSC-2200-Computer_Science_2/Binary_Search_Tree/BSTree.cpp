
#include "BSTree.h"

template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode ( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr )
// Creates a binary search tree node containing data item elem, left
// child pointer leftPtr, and right child pointer rightPtr.
  : dataItem(nodeDataItem),
    left(leftPtr),
    right(rightPtr)
{
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree ()

// Creates an empty tree.
{
	root = NULL;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree ( const BSTree<DataType,KeyType>& other )
//copy constructor
{
    *this = other;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>:: operator= ( const BSTree<DataType,KeyType>& other )
// Sets a tree to be equivalent to the tree "other".
{
    if (*this == &other)
    {
        return *this;
    }

    clear();
    root = other.root;
    
    return *this;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::~BSTree ()
// Frees the memory used by a tree.
{
    clear();
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::insert ( const DataType& newDataItem )
// Inserts newDataItem into a tree. If an data item with the same key
// as newDataItem already exists in the tree, then updates that
// data item's data with newDataItem's data.
{
    insertHelper(root, newDataItem);
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::retrieve ( const KeyType& searchKey, DataType& searchDataItem ) const
// Searches a tree for the data item with key searchKey. If the data item
// is found, then copies the data item to searchDataItem and returns true.
// Otherwise, returns false with searchDataItem undefined.
{
    return retrieveHelper(root, searchKey, searchDataItem);
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::remove ( const KeyType& deleteKey )
// Removes the data item with key deleteKey from a tree. If the
// data item is found, then deletes it from the tree and returns true.
// Otherwise, returns false.
{
    return removeHelper(root,deleteKey);
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeKeys () const
// Outputs the keys in a tree in ascending order.

{
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clear ()
// Removes all the nodes from a tree.
{
    delete *this;
    root = NULL;
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::isEmpty () const

// Returns true if a tree is empty. Otherwise returns false.

{
	return (root == NULL);
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getHeight () const
// Returns the height of a tree.

{
	return -1;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getCount () const
// Returns the number of nodes in the tree

{
	return -1;
}

// Helpers

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::insertHelper    ( BSTreeNode *&p, const DataType &newDataItem )
{
    if (!p)
    {
        p = new BSTreeNode(newDataItem, NULL, NULL);
    }
    else if(newDataItem < p->dataItem)
    {
        if (p->dataItem != NULL)
        {
            insertHelper(p->left, newDataItem);
        }
        else
        {
            p->left = BSTreeNode(newDataItem, NULL, NULL);
        }
    }
    else if (newDataItem > p->dataItem)
    {
        if (p->dataItem != NULL)
        {
            insertHelper(p->right, newDataItem);
        }
        else
        {
            p->right = BSTreeNode(newDataItem, NULL, NULL);
        }

    }
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::retrieveHelper  ( BSTreeNode *p, const KeyType& searchKey, DataType &searchDataItem ) const
{
    if (!p)
    {
        return false;
    }
    else
    {
        if (searchKey == p->dataItem)
        {
            searchDataItem = p->dataItem;
            return true;
        }
        else if (searchKey > p->dataItem)
        {
            retrieveHelper(p->right, searchKey, searchDataItem);
        }
        else
        {
            retrieveHelper(p->left, searchKey, searchDataItem);
        }
    }
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::removeHelper    ( BSTreeNode *&p, const KeyType& deleteKey )
{
    if(!p)
    {
        return false;
    }
    else
    {
        if(deleteKey == p->dataItem)
        {
            if(p->left == NULL && p->right == NULL)
            {
                delete p;
                p = NULL;
            }
            else if(p->left == NULL)
            {
                BSTreeNode* temp = p;
                p = p->right;
                delete temp;
            }
            else if(p->right == NULL)
            {
                BSTreeNode* temp = p;
                p = p->left;
                delete temp;
            }
            else
            {
                BSTreeNode* temp = p->left;
                while(temp->right != NULL)
                {
                    temp = temp->right;
                }
                
                p->dataItem = temp->dataItem;
                removeHelper(temp->dataItem, p->left);
            }
            return true;
        }
        else if(deleteKey < p->dataItem)
        {
            return removeHelper(deleteKey, p->left);
        }
        else
        {
            return removeHelper(deleteKey, p->right);
        }
    }
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::cutRightmost    ( BSTreeNode *&r, BSTreeNode *&delPtr )
{
    
}
template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeKeysHelper ( BSTreeNode *p ) const
{
    if(p)
    {
        writeKeysHelper(p->left);
        cout<<p->dataItem<<" ";
        writeKeysHelper(p->right);
        cout<<p->dataItem<<" ";
    }
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clearHelper     ( BSTreeNode *p )
{
    if(p)
    {
        clearHelper(p->left);
        clearHelper(p->right);
        delete p;
    }
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::showHelper      ( BSTreeNode *p, int level ) const
{
    
}

template < typename DataType, class KeyType >
int  BSTree<DataType, KeyType>::getHeightHelper ( BSTreeNode *p ) const
{
    static int height = 0;
    
    if(!p)
    {
        getHeightHelper(p->left);
        getHeightHelper(p->right);
        height++;
    }

    return height;
}

template < typename DataType, class KeyType >
int  BSTree<DataType, KeyType>::getCountHelper  ( BSTreeNode *p ) const
{
    if(!p)
    {
        return 0;
    }
    else
    {
        return getCountHelper(p->left)+getCountHelper(p->right)+1;
    }
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::copyTree        ( const BSTree<DataType,KeyType> &otherTree )
{
    copyTreeHelper(root, otherTree);
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::copyTreeHelper  ( BSTreeNode *&p, const BSTreeNode *otherPtr )
{
    p = otherPtr;
}


#include "show9.cpp"
