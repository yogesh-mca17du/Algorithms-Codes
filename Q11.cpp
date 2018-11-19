#include<iostream>

using namespace std;

//global array
int **memorize_table; //2D array containing values returned by function call anti_squad() for every valid combination of n0 and max

int anti_squad(int no, int max, int min_in_grp)
{

	/*
	Objective :	Calculates no. of partitions possible of 'n' people such that each group has atmost 'max' and atleast 'min' number of people.

	Input variables
                    -no : total number of people to be partitioned
                    - max : maximum number of people allowed in each group
                    - min : minimum number of people required in each group(this value remains same for each recursive call)

	Return value :no. of partitions possible

	*/

	//when there are zero people, only one partiton is possible that is {}
	if(no == 0)
		return 1;

	//when the total no. of people is less than minimum count required for each group
	if(no < min_in_grp )
		return 0;

	//when value of maximum people allowed is less than minimum people required.
	if(max < min_in_grp)
		return 0;

	/*two recursive call
		1. returns partition count containing max
	 	2. returns partition count not containing max
	 together they give total number of possible partitions
	*/

	//when the value is not already present in the table
	if(memorize_table[no][max] == -1)
			memorize_table[no][max] = anti_squad(no-max, max, min_in_grp) + anti_squad(no,max-1, min_in_grp);

	return memorize_table[no][max];
}

//driver code
int main()
{
	cout<<"\n\n\t***ANTI-SQAUD PARTITIONING PROBLEM****";
	int no,min_in_group;

	while(true){
		cout<<"\n\nEnter total no.of people : ";
		cin>>no;
		if(no>0)
			break;
		cout<<"\n\nNumber of people cannot be less than 1!!";
	}
	while(true){
		cout<<"\n\nEnter minimum count of people required in each group : ";
		cin>>min_in_group;
		if(min_in_group>0)
			break;
		cout<<"\n\nMinimum count cannot be less than 1!!";
	}

	memorize_table = new int*[no+1];
	for(int i=0;i<=no;i++)
		memorize_table[i] = new int[no+1];

	for(int i=0;i<=no;i++)
		for(int j=0;j<=no;j++)
			memorize_table[i][j] = -1;
	cout<<"\n\nNo. of ways in which anti sqauds can be formed is : "<<anti_squad(no,no,min_in_group);
	return 0;
}
