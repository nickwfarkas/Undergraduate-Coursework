//
//  main.cpp
//  Assignment_3
//
//  Created by Nicholas Farkas on 3/20/22.
//

#include <iostream>
#include <stdc++.h>


void DFS(vector<int> &traveled, int start, list<int> *adj);

class Graph
{
    int V; // No. of vertices
    list<int> *adj; // adjacency lists

    // Add whatever functions you need here
public:
    Graph(int V);
    void addEdge(int v, int w);
    int findMother();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to vâ€™s list.
}

// Returns a mother vertex if exists. Otherwise returns -1
int Graph::findMother()
{
    vector <int> traveled;
    int temp = 0;

    for (int i = 0; i < V; i++)
    {
        traveled.push_back(0);
    }

    for (int i = 0; i < V; i++)
    {
        if (!traveled[i])
        {
            DFS(traveled, i, adj);
            temp = i;
        }
    }
    
    traveled.clear();
    
    for (int i = 0; i < V; i++)
    {
        traveled.push_back(0);
    }
    
    DFS(traveled, temp, adj);
    
    for (int i = 0; i < V; i++)
    {
        if (!traveled[i])
        {
            return -1;
        }
    }

    return temp;
}

void DFS(vector<int> &traveled, int start, list<int> *adj)
{
    traveled[start] = true;
    
    list<int>::iterator current = adj[start].begin();
    list<int>::iterator end = adj[start].end();
    while (current != end)
    {
        if (!traveled[*current])
        {
            DFS(traveled, *current, adj);
        }
        ++current;
    }
}

// Driver program to test above functions
int main()
{
    // Create the graph given in Figure 22.5(c)
    Graph g(8);
    g.addEdge(0, 2);
    g.addEdge(0, 6);
    g.addEdge(3, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 1);
    g.addEdge(4, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 7);
    g.addEdge(7, 2);

    cout << "Here is a mother vertex: " << g.findMother() << "\n";

    return 0;
}
