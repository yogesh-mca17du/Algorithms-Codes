#include<iostream>

using namespace std;

class Bellman
{
    int *dis;
    int *pi;
    int capacity;

    public:
    Bellman(int);
    void initialize(int);
    void bFord(int **);
};

Bellman::Bellman(int cap)		//PARAMETERISED CONSTRUCTOR USED FOR INITIALIZATION
{
    capacity = cap;

    dis = new int[capacity];
    pi = new int[capacity];
}

void Bellman::initialize(int s)		//INITIALIZING SOURCE VERTEX
{
    for(int i=0; i<capacity; i++)
    {
        dis[i]=9999;
        pi[i]=0;
    }
    dis[s]=0;
}

void Bellman::bFord(int **adj)
{
    int u, j, flag=0;

    for(int k=0; k<capacity; k++)
    {
        for(int i=0; i<capacity; i++)
        {
            for(int j=0; j<capacity; j++)
            {

                if(adj[i][j]!=0)
                {
                    if(dis[j] > dis[i]+adj[i][j])		//CHECK CONDITION TO STORE APPROPRIATE VALUES IN THE TABLE
                    {
                        dis[j] = dis[i]+adj[i][j];
                        pi[j] = i;
                    }
                }
            }
        }
    }

    for(int i=0; i<capacity; i++)
    {
        for(int j=0; j<capacity; j++)
        {
            if(adj[i][j]!=0)
            {
                if(dis[j] > dis[i]+adj[i][j])
                {
                        flag=1;
                        cout<<"\nSORRY,,,,INVALID INPUT";		//INVALID INPUT 
                }
            }
        }
    }

    if(flag==0)
    {
        cout<<"\nFIANLISED RESULT IS ";
        for(int i=0; i<capacity; i++)
            cout<<"\nVertex "<<i+1<<", distance: "<<dis[i];
    }
}

int main()
{
    int v, e, src, dest, cost, strt;

    cout<<"NO. OF VERTICES IN GRAPH";
    cin>>v;

    int **adj = new int*[v];
    for(int i=0; i<v; i++)
        adj[i]= new int[v];

    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
            adj[i][j]=0;
    }

    cout<<"\nNO. OF EDGES IN GRAPH ";
    cin>>e;

    cout<<"\nDETAILS FOR EACH EDGE\n";
    for(int i=0; i<e; i++)
    {
        cout<<"\nSource Vertex: ";
        cin>>src;
        cout<<"Destination Vertex: ";
        cin>>dest;
        cout<<"Cost: ";
        cin>>cost;
        adj[src-1][dest-1]=cost;
    }

    cout<<"\nAdjacency Matrix\n";
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }

    cout<<"\nEnter starting vertex: ";
    cin>>strt;

    Bellman b(v);
    b.initialize(strt-1);
    b.bFord(adj);

    return 0;
}
