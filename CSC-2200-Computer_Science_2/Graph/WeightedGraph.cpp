//--------------------------------------------------------------------
//
//  Laboratory 12                                    WeightedGraph.cpp
//
//--------------------------------------------------------------------

#ifndef WEIGHTEDGRAPH_CPP
#define WEIGHTEDGRAPH_CPP

using namespace std;

#include "WeightedGraph.h"
#include "config.h"


//--------------------------------------------------------------------

WeightedGraph::WeightedGraph(int maxNumber)
:maxSize(maxNumber),size(0)

// Creates an empty graph. Allocates enough memory for maxNumber
// vertices (defaults to defMaxGraphSize).
{
    vertexList = new Vertex[maxSize];
    adjMatrix = new int[maxSize*maxSize];
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

WeightedGraph::WeightedGraph(const WeightedGraph& other)
:maxSize(other.maxSize),size(other.size)
// Creates an empty graph. Allocates enough memory for maxNumber
// vertices (defaults to defMaxGraphSize).
{
    vertexList = new Vertex[maxSize];
    
    for(int i = 0; i < size; i++)
    {
        vertexList[i] = other.vertexList[i];
    }

    adjMatrix = new int[maxSize*maxSize];
    
    for(int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
        {
            adjMatrix[maxSize*row+col] = other.adjMatrix[maxSize*row+col];
        }
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

WeightedGraph& WeightedGraph:: operator= ( const WeightedGraph& other )

// Copies from another WeightedGraph. 
{
    if(this == &other)
    {
        return *this;
    }

    if(maxSize < other.maxSize)
    {
        delete[] vertexList;
        delete[] adjMatrix;

        vertexList = new Vertex[other.maxSize];
        adjMatrix = new int [other.maxSize*other.maxSize];
    }

    maxSize = other.maxSize;
    size = other.size;

    for(int i = 0; i < size; i++)
    {
        vertexList[i] = other.vertexList[i];
    }

    for(int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
        {
            adjMatrix[maxSize*row+col] = other.adjMatrix[maxSize*row+col];
        }
    }
    
    return *this;
}

//--------------------------------------------------------------------

WeightedGraph:: ~WeightedGraph ()

// Frees the memory used by a graph.
{
    delete [] vertexList;
    delete [] adjMatrix;
}

//--------------------------------------------------------------------

void WeightedGraph:: insertVertex ( const Vertex& newVertex ) throw ( logic_error )

// Inserts newVertex into a graph. If a vertex with the same label
// as newVertex already exists in the graph, then updates that
// vertex's data with newVertex's data.
{
    int pos = getIndex(newVertex.getLabel());

    if (size == maxSize)
    {
        throw logic_error("Graph is full");
    }

    vertexList[size] = newVertex;

    if (pos == size)
    {
        size++;
        for (int j = 0 ; j < size ; j++)
        {
            setEdge(size-1, j, INFINITE_EDGE_WT);
            setEdge(j, size-1, INFINITE_EDGE_WT);
        }
    }

}

//--------------------------------------------------------------------

void WeightedGraph:: insertEdge ( const string& v1, const string& v2, int wt )
    throw ( logic_error )

// Insert an edge with the specified weight between vertices
// v1 and v2.
{
    int i = getIndex(v1);
    int j = getIndex(v2);

    if ( i >= size )
    {
        throw logic_error("Out of range");
    }

    if ( j >= size )
    {
        throw logic_error("Out of range");
    }
    
    setEdge(i,j,wt);
    setEdge(j,i,wt);
}

//--------------------------------------------------------------------

bool WeightedGraph:: retrieveVertex ( const string& v, Vertex &vData ) const

// Searches a graph for vertex v. If the vertex is found, then copies
// the vertex data to vData and returns 1. Otherwise, returns 0 with
// vData undefined.
{
    bool result;
    int pos = getIndex(v);
    
    if (pos != size)
    {
        vData = vertexList[pos];
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

//--------------------------------------------------------------------

bool WeightedGraph:: getEdgeWeight ( const string& v1, const string& v2, int &wt ) const
    throw ( logic_error )

// If there is an edge connecting vertices v1 and v2, then returns 1
// with wt returning the weight of the edge. Otherwise, returns 0
// with wt undefined.
{
    int i = getIndex(v1) ;
    int j = getIndex(v2) ;

    if (i >= size)
    {
        throw logic_error("Out of range");
    }

    if (j >= size)
    {
        throw logic_error("Out of range");
    }

    wt = getEdge(i, j);
    
    return (wt != INFINITE_EDGE_WT);
}

//--------------------------------------------------------------------

void WeightedGraph:: removeVertex ( const string& v ) throw ( logic_error )

// Removes vertex v from a graph.
{
    int i = getIndex(v);

    if (i >= size)
    {
        throw logic_error("Out of range");
    }

    for (int j = i ; j < size-1 ; j++)
    {
        vertexList[j] = vertexList[j+1];
    }

    for (int j = i ; j < size-1 ; j++)
    {
        for (int k = 0 ; k < size ; k++)
        {
            setEdge(j,k, getEdge(j+1,k));
        }
    }

    for (int j = i ; j < size-1 ; j++)
    {
        for (int k = 0 ; k < size ; k++)
        {
            setEdge(k,j, getEdge(k,j+1));
        }
    }

    size--;
}

//--------------------------------------------------------------------

void WeightedGraph:: removeEdge ( const string& v1, const string& v2 ) throw ( logic_error )

// Removes the edge between vertices v1 and v2 from a graph.

{
    int i = getIndex(v1);
    int j = getIndex(v2);

    if (i >= size)
    {
        throw logic_error("Out of range");
    }

    if ( j >= size )
    {
        throw logic_error("Out of range");
    }

    setEdge(i,j, INFINITE_EDGE_WT);
    setEdge(j,i, INFINITE_EDGE_WT);
}

//--------------------------------------------------------------------

void WeightedGraph:: clear ()

// Removes all the vertices and edges from a graph.

{
    size = 0;
}

//--------------------------------------------------------------------

bool WeightedGraph:: isEmpty () const

// Returns 1 if a graph is empty. Otherwise, returns 0.

{
	return size == 0;
}

//--------------------------------------------------------------------

bool WeightedGraph:: isFull () const

// Returns 1 if a graph is full. Otherwise, returns 0.

{
	return size == maxSize;
}

//--------------------------------------------------------------------

void WeightedGraph:: showStructure () const

// Outputs a graph's vertex list and adjacency matrix. This operation
// is intended for testing/debugging purposes only.

{
    if ( size == 0 ) {
       cout << "Empty graph" << endl;
    } else {
       cout << endl << "Vertex list : " << endl;
       for ( int row = 0 ; row < size ; row++ ) {
           cout << row << '\t' << vertexList[row].getLabel();
#if LAB12_TEST2
	   cout << '\t' << vertexList[row].getColor();
#endif
	   cout << endl;
       }

       cout << endl << "Edge matrix : " << endl << '\t';
       for ( int col = 0 ; col < size ; col++ )
           cout << col << '\t';
       cout << endl;
       for ( int row = 0 ; row < size ; row++ )
       {
           cout << row << '\t';
           for ( int col = 0 ; col < size ; col++ )
           {
               int wt = getEdge(row,col);
               if ( wt == INFINITE_EDGE_WT )
                  cout << "- \t";
               else
                  cout << wt << '\t';
           }
           cout << endl;
       }
    }
}




//--------------------------------------------------------------------
//
//  Facilitator functions
//

int WeightedGraph:: getIndex ( const string& v ) const

// Returns the adjacency matrix index for vertex v. Returns size if
// the vertex does not exist.

{
    int j;
 
    for (j = 0 ; j < size && (vertexList[j].getLabel() != v); j++);
    
    return j;
}
       
//--------------------------------------------------------------------

int WeightedGraph:: getEdge ( int row, int col ) const

// Gets adjMatrix[row][col].

{
    return adjMatrix[row*maxSize+col];
}

void WeightedGraph:: setEdge ( int row, int col, int wt )

// sets adjMatrix[row][col].

{
    adjMatrix[maxSize*row+col] = wt;
}


#endif
