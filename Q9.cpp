#include<iostream>

using namespace std;

struct contestant
{
	int stime, btime, rtime, num;
};

void copy(contestant &c1, contestant &c2) //equating 1 element to another
{
	/*
    Objective: the function aims at copying the values of one object of structure contestant to another object of the structure.
    Input Variables:
        c1: object c1
        c2: object c2
    Return Value: None
    */
	
	c1.num = c2.num;
	c1.stime = c2.stime;
	c1.btime = c2.btime;
	c1.rtime = c2.rtime;
}

bool compare(contestant c1, contestant c2) //function compares the two on the basis of bike time + run time
{
  	/*
    Objective: the function aims at comparing the sum of running time and biking time of two objects of structure contestant.
    Input Variables:
        c1: object c1
        c2: object c2
    Return Value:
        True if, c1 < c2
        else, False
    */
	
	int s1  = c1.stime;
	int br1 = c1.btime + c1.rtime;
	int s2  = c2.stime;
	int br2 = c2.btime + c2.rtime;
	if(br1 < br2)
		return true;
	else
		return false;
}

void sort(contestant c[], int n)  //insertion sort
{

   /*
    Objective: the function aims at sorting the input on the basis of decreasing running + biking time.
    Input Variables:
        c: array of objects
        n: size of the c
    Return Value: None
   
   */
	
	int i,j;
	contestant con;
	for(i=1; i<n; i++)
	{
		copy(con,c[i]); //to copy one element's data to a key
		j=i-1;
		while(j>=0 && compare(c[j],con))
		{
			copy(c[j+1],c[j]);
			j=j-1;
		}
		copy(c[j+1], con);
	}
}

int main()
{
	int n;
	while(true){
		cout<<"\nEnter number of contestants: ";
		cin>>n;
		if(n>=1)
			break;
		cout<<"\nNumber of contestants should be at least 1\n";
	}
	contestant *c = new contestant[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter expected swimming time, biking time and running time of contestant "<<i+1<<": \n";
		cin>>c[i].stime>>c[i].btime>>c[i].rtime;
		c[i].num=i+1;
	}
	sort(c,n);
	cout<<"\nOrder of sending out contestants is \n";
	for(int j=0; j<n; j++)
		cout<<c[j].num<<" ";
	return 0;
}
