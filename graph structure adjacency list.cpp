/*
 Here, we are implementing DFS and BFS on a graph,
 with the graph as a structure including the visited array
 and adjacency list.
*/

#include<bits/stdc++.h>

using namespace std;

struct node_ll
{
    int data;
    struct node_ll* next;

    node_ll(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};

struct graph
{
    node_ll *adj;
    int *visited;

    graph(int v, int e)
    {
        for(i=1;i<(v+1);i++)
            adj[i]=new node_ll(i);

        for(i=0;i<e;i++)
        {
            for(i=0;i<e;i++)
            {
                cout<<"\n\nEnter the starting vertex: ";
                cin>>V1;
                cout<<"Enter the ending vertex: ";
                cin>>V2;


            }



        }
    }
};

int main()
{
    cout<<endl<<endl;
    return 0;
}
