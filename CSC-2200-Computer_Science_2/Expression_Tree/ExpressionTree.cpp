
#include "ExpressionTree.h"

template <typename DataType>
ExprTree<DataType>::ExprTreeNode:: ExprTreeNode ( char nodeDataItem,
                              ExprTreeNode *leftPtr,
                              ExprTreeNode *rightPtr )

// Creates an expreesion tree node containing data item nodeDataItem,
// left child pointer leftPtr, and right child pointer rightPtr.

  : dataItem(nodeDataItem),
    left(leftPtr),
    right(rightPtr)

{}

template <typename DataType>
ExprTree<DataType>:: ExprTree ()

// Creates an empty expression tree.
	: root(0)

{}

template <typename DataType>
ExprTree<DataType>::ExprTree(const ExprTree& valueTree)

// Copy constructor. Creates a copy of valueTree.

{
    root = valueTree.root;
    *this = valueTree;
}

template <typename DataType>
ExprTree<DataType>& ExprTree<DataType>::operator=(const ExprTree& source)
// Overloads the assignment operator for any data type.
{
    if(this == &source)
    {
        return *this;
    }
    
    copyHelper(source);
    return *this;
}


template <typename DataType>
void ExprTree<DataType>::copyHelper(ExprTreeNode *&p)
// Recursive private helper for the copy constructor and overloaded
// assignment operator. Creates a copy of the subtree pointed to by p, 
// p points to the new subtree.
{
    if(this)
    {
        ExprTreeNode *l = NULL;
        ExprTreeNode *r = NULL;
        copyHelper(left);
        copyHelper(right);
        this = new ExprTreeNode(p->dataItem, left, right);
    }
}


template <typename DataType>
ExprTree<DataType>::~ExprTree ()
// Frees the memory used by an expression tree.

{
    clear();
}

template <typename DataType>
void ExprTree<DataType>::build ()
// Builds a new expression tree from standard input (cin)

{
    buildHelper(root);
}

template <>
void ExprTree<float>::buildHelper(ExprTreeNode*& p)
// Specialized function to help build trees of floats.
// Input is single digit ints or operators.

{
    char temp;
    cin >> temp;
    p = new ExprTreeNode(temp, NULL, NULL);

    if(temp == '+' || temp == '-' || temp == '*' || temp == '/')
    {
        buildHelper(p->left);
        buildHelper(p->right);
    }
}


template <>
void ExprTree<bool>::buildHelper(ExprTreeNode*& p)
// Specialized function to help build boolean trees.
// Input is 0, 1, or operators.
{
    char temp;
    cin >> temp;
    p = new ExprTreeNode(temp, NULL, NULL);

    if(temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '0' || temp == '1')
    {
        buildHelper(p->left);
        buildHelper(p->right);
    }
}


template <typename DataType>
void ExprTree<DataType>::expression () const
// Public function to print out fully parenthesized expression tree.
{
    exprHelper(root);
}

template <typename DataType>
void ExprTree<DataType>::exprHelper(ExprTreeNode* p) const
// Private helper function to print out fully parenthesized expression tree.
{
    if(isdigit(p->dataItem))
    {
        cout<< p->dataItem;
    }
    else
    {
        cout<<"(";
        exprHelper(p->left);
        cout<<p->dataItem;
        exprHelper(p->right);
        cout<<")";
    }
}

template <typename DataType>
DataType ExprTree<DataType>::evaluate() const throw (logic_error)
// Public function to evaluate an expression tree.

{
    if(root)
    {
        throw("Tree is empty");
    }

	return evalHelper(root);
}


template <>
float ExprTree<float>::evalHelper(ExprTreeNode* p) const
// Private helper function to evaluate an expression tree with a float
// result.

{
    switch(p->dataItem)
    {
        case '+':
            return (evalHelper(p->left) + evalHelper(p->right));
            break;
        case '-':
            return (evalHelper(p->left) - evalHelper(p->right));
            break;
        case '*':
            return (evalHelper(p->left) * evalHelper(p->right));
            break;
        case '/':
            return (evalHelper(p->left) / evalHelper(p->right));
            break;
        default:
            return (p->dataItem - '0');
            break;
    }
}

template <>
bool ExprTree<bool>::evalHelper(ExprTreeNode* p) const
// Private helper function to evaluate an boolean expression tree with a 
// bool result.

{
    switch(p->dataItem)
    {
        //Case is addition
        case '+':
            return (evalHelper(p->left) + evalHelper(p->right));
            break;
        //Case is subtraction
        case '-':
            return (evalHelper(p->left) - evalHelper(p->right));
            break;
        //Case is multiplication
        case '*':
            return (evalHelper(p->left) * evalHelper(p->right));
            break;
        //Case is division
        case '/':
            return (evalHelper(p->left) / evalHelper(p->right));
            break;
        //Case is a digit, so convert from char to int
        default:
            return (p->dataItem - '0');
            break;
    }
}

template <typename DataType>
void ExprTree<DataType>::clear ()
// Removes all the nodes from an expression tree.
// same as destructor
{
    clearHelper(root);
}

template <typename DataType>
void ExprTree<DataType>::clearHelper(ExprTreeNode *p)

// Recursive helper for the clear() function. Clears the subtree
// pointed to by p.
{
    if(p)
    {
        clearHelper(p->left);
        clearHelper(p->right);
        delete p;
        p = NULL;
    }
}

template <typename DataType>
void ExprTree<DataType>::commute()
// Public operator to commute the tree.

{
    commuteHelper(root);
}


template <typename DataType>
void ExprTree<DataType>::commuteHelper(ExprTreeNode* p)
// Private recursive helper function to commute the tree.
{
    if(!p)
    {
        cout<<"Tree is empty"<<endl;
    }
        return;
    if(!isdigit(p->dataItem))
    {
        ExprTreeNode* temp = p->left;
        p->left = p->right;
        p->right = temp;
    }
    commuteHelper(p->left);
    commuteHelper(p->right);
}

template <typename DataType>
bool ExprTree<DataType>::isEquivalent(const ExprTree& source) const
// Public operator to determine whether two expression trees are equivalent.

{
    return isEquivalentHelper(root, source.root);
}

template <typename DataType>
bool ExprTree<DataType>::isEquivalentHelper(const ExprTreeNode* x,
	const ExprTreeNode* y) const
// Private recursive assistant function to determine whether two expression 
// trees are equivalent.

{
    if(x == NULL && y == NULL)
    {
        return true;
    }
    else
    {
        if(x->dataItem == y->dataItem)
        {
            if(isEquivHelper(x->left, y->left) && isEquivHelper(x->right, y->right))
            {
                return true;
            }
            else if (isEquivHelper(x->left, y->right) && isEquivHelper(x->right, y->left))
            {
                if(x->dataItem == '+' || x->dataItem == '*')
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
    }
    return false;
}


template <typename DataType>
void ExprTree<DataType>::showStructure() const

// Outputs an expression tree. The tree is output rotated counter-
// clockwise 90 degrees from its conventional orientation using a
// "reverse" inorder traversal. This operation is intended for testing
// and debugging purposes only.

{
	// No isEmpty function in this class. Add a private one if you wish.
	if (root == 0)
		cout << "Empty tree" << endl;
	else
	{
		cout << endl;
		showHelper(root, 1);
		cout << endl;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
void ExprTree<DataType>::showHelper(ExprTreeNode *p, int level) const

// Recursive helper for the showStructure() function. Outputs the
// subtree whose root node is pointed to by p. Parameter level is the
// level of this node within the expression tree.

{
	int j;   // Loop counter

	if (p != 0)
	{
		showHelper(p->right, level + 1);        // Output right subtree
		for (j = 0; j < level; j++)   // Tab over to level
			cout << "\t";
		cout << " " << p->dataItem;        // Output dataItem
		if ((p->left != 0) &&          // Output "connector"
			(p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showHelper(p->left, level + 1);         // Output left subtree
	}
}
