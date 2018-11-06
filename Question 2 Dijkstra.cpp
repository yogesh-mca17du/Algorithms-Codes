// Question 2 : Dijkstra 
#include<iostream>
#define maxi 10
using namespace std;
class dijik
{
	public: dijik();
		void input();
		void di();
		void disp();
		void calling(int);
		int minkey(int);
		int ad[maxi][maxi];
		char col[maxi];
		int s,d,key[maxi],size,p;
		int *parent;


};

dijik :: dijik()		//CONSTRUCTOR TO INITIALIZE VERTICES AND EDGES
{
	size=0;
	for(int i=0;i<maxi;i++)
	{
		col[i]='W';
		for(int j=0;j<maxi;j++)
		ad[i][j]=0;
	}
}

void dijik :: input()	//FETCHING USER INPUTS
{
	int i,j,n,e;
	cout<<"\nEnter the no. of vertex: ";
	cin>>n;
	size=n;
	cout<<"\nEnter the no. of edges: ";
	cin>>e;
	cout<<"\nEnter edges:\n";
	int x;
	for(int k=0; k<e; k++)
	{
		cout<<"\nVertex1: ";
		cin>>i;
		cout<<"Vertex2: ";
		cin>>j;
		cout<<"Weight: ";
		cin>>x;
		ad[j-1][i-1]=ad[i-1][j-1]=x;
	}
	cout<<"\nMATRIX REPRESENTATION:\n";		//DISPLAYING ADJACENCY MATRIX FOR THE GRAPH
	for(int a=0;a<size;a++)
	{
		for(int b=0;b<size;b++)
		{
			cout<<ad[a][b]<<" ";
		}
		cout<<endl;
	}


	cout<<"\nEnter the starting node: ";
	cin>>s;
	cout<<"\nEnter the destination node: ";
	cin>>d;
	parent=new int[size];
}


void dijik :: di()
{
	int u;
	for(int i=0;i<size;i++)
	{
		key[i]=1000;
		col[i]='W';
		parent[i]=-1;
	}
	key[s-1]=0;
	for(int j=s-1;j<size;j++)
	{
		u=minkey(size);				
		col[u]='B';
		for(int v=0;v<size;v++)
		{
			if(ad[u][v]!=0 && col[v]=='W'&& (key[u]+ad[u][v])<key[v])
			{
				parent[v]=u;
				key[v]=ad[u][v]+key[u];
			}
		}
	}
	cout<<"\nSPANNED PATH:\n";

	cout<<"CHILD"<<" "<<"PARENT"<<" "<<"WEIGHT"<<endl;
	for(int l=0;l<size;l++)
	{
		cout<<"("<<l+1<<")    ("<<parent[l]+1<<")  : ("<<key[l]<<")"<<endl;
	}
}

int dijik :: minkey(int sz)		
{

	int v=0;
	int min_index=0;
	int min=1000;
	for(v=0;v<sz;v++)
	{
		if(col[v]=='F'&& key[v]<min)
		{
			min=key[v];
			min_index=v;
		}
	}
	return min_index;
}


void dijik :: disp()
{
	cout<<"\nRoute is : ";
	p=d-1;
	calling(p);
	cout<<"\b\b";
	cout<<endl;
}

void dijik :: calling(int a)		//PARENT CALLING FUNCTION
{
	if(parent[a]!=-1)
	{
		calling(parent[a]);
	}
	cout<<a+1<<"  ";

}
int main()
{
	dijik dij;
	dij.input();
	dij.di();
	dij.disp();
	return 0;
}
