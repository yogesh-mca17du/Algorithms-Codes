#include<iostream>

using namespace std;

//global variables
bool **adj_matrix;
bool *isPotential;


//functions
int Count(int size, int person_x)
{
	/*

	Objective :This function calculates number of people that a person_x knows.

	Input variables
                - size : size of array isPotenital
                - person_x : person for which number of his/her acquaintance has to be calculated

	Return value :# person_x knows

	*/

	int cnt=0;
	for(int i=1; i<=size; i++){

		// check if person 'i' is an invitee && if person 'i' and person_x know each other
		if(isPotential[i] && adj_matrix[i][person_x])
			cnt++;
	}
	return cnt;
}


void invitees(int n)
{
    /*

	Objective :This function print the final invitees and the count of invitees.
	Input Variables : n -number of people
	Return : None

	*/

	int cnt = 0;
	cout<<"\n\nAlice can invite following people\n\n";
	for(int i=1; i<=n; i++){
		if(isPotential[i]){
			cout<<i<<"\t";
			cnt++;
		}
	}
	if(cnt == 0)
		cout<<"\n\nNo one can be invited.";
	else
		cout<<"\n\nMaximum number of people who can be invited is : "<<cnt;

}

void plan_party(int n){

	/*
    Objective :
        This function computes all persons who can be invited for a party out of n people based on following conditions:
		1. Every person invited should know at least five other people that are invited.
		2. Every person invited should not know at least five other people that are invited.
		3. Number of invitees is maximized

	Input variable
                - n : Number of people to choose from

	Return value : None


	*/

	int potential_count = n;
	for(int j=1; j<=n; j++)
	{

			int known = count(n,j);                 //number of people j knows

			int unknown = potential_count - known - 1;          //number of people j does not know

			//if a potenital invitee disqualifies any of condition 1 or 2, make him invalid and start checking from person 1 again
			if( isPotential[j] && (known < 5 || unknown < 5) )
			{
				isPotential[j]=false;
				potential_count--;
				j = 0;
				//if number of potenital invitee become less than 11, there is no way we can find a person who know 5 person and does not know 5 person
				if(potential_count < 11){
					for(int i=1;i<=n;i++)
						isPotential[i] = false;
					break;
				}
			}
	}

}

//driver code
int main()
{
	int no;
	while(true){
		cout<<"\nEnter value of n(>=11): ";
		cin>>no;
		if(no>=11)
			break;
	}


	adj_matrix = new bool*[no+1];
	for(int i=0;i<=no;i++)
		adj_matrix[i] = new bool[no+1];

	isPotential = new bool[no+1];

	//initialize adj_matrix such that nobody knows anyone
	for(int i=1; i<=no; i++)
	{
		isPotential[i] = true;
		for(int j=1; j<=no; j++)
		{
			adj_matrix[i][j] = false;
		}
	}

	char choice;

	//input pairs
	while(true)
	{
		int x, y;
		cout<<"\nEnter pair (x,y) who know each other \n";
		cout<<"\n Person x : ";
		cin>>x;
		if(x<1 || x>no){
			cout<<"\nInvald pair!Enter again!\n";
			continue;
		}
		cout<<"\n Person y : ";
		cin>>y;
		if(y<1 || y>no || y == x){
			cout<<"\nInvald pair!Enter again!\n";
			continue;
		}

		//update adjacency matrix
		adj_matrix[x][y] = true;
		adj_matrix[y][x] = true;
		cout<<"\nAre there any more pairs who know each other?(y/n): ";
		cin>>choice;
		if(choice=='n')
			break;
		x++;
		y++;
	}
	plan_party(no);
	invitees(no);
	return 0;
}
