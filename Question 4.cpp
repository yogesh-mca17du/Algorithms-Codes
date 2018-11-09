//	Question no. : 4 - Program to calculate maximum revenue by placing a subset of billboard on the highway
 
#include<iostream> 
using namespace std; 

#define gap 5

int maximumRevenue(int tot_miles, int site[], int revenue[], int no_of_sites) 
{ 
	int *maxRevenue = new int[tot_miles+1]; 				// maxRevenue will store maximum revenue at each mile from 0 to total_miles
	for(int i=0;i<=tot_miles;i++){
		maxRevenue[i] = 0;
	}
	 
	int next = 0;
	//If the billboard is present at 0th mile
	if(site[0] == 0){
		maxRevenue[0] = revenue[0];
		next = 1;
	}
	
	for (int i = 1; i <= tot_miles; i++) 
	{ 
		if (next < no_of_sites) 						//tests whether all billboards are traversed or not. 
		{ 
			if (site[next] != i) 						//if there is not a billboard at ith mile, copy the maximum revenue from previous mile. 
				maxRevenue[i] = maxRevenue[i-1];  
			else										//if there is a billboard for this mile, either include this billboard or ignore it.							
			{ 
				if (i <= gap) 							//when site is in interval [0,gap], only one site from this interval can be a part final subset
					maxRevenue[i] = max(maxRevenue[i-1], revenue[next]); 
				else									//if revenue after including this billboard(with billboards before gap_size) is greater then previous revenue, then include it otherwise discard it.								
					maxRevenue[i] = max(maxRevenue[i-1], maxRevenue[i-gap-1]+revenue[next]); 
				next++; 
			} 
		} 
		else											//when all billboards are tranversed, keep copying latest revenue
			maxRevenue[i] = maxRevenue[i - 1]; 
	} 

	return maxRevenue[tot_miles]; 
} 
 
int main() 
{ 
	cout<<"\n\n\t\t\tBILLBOARD PROBLEM";
	
	int total_miles;
	int *site = new int[total_miles];
	int *revenue = new int[total_miles];
	int count = 0;
	cout<<"\n\nEnter total number of miles from west to east: ";
	cin>>total_miles;
	while(true){
		cout<<"\nEnter next site( -1 to stop ): ";
		cin>>site[count++];
		
		//testing whether site has exceeded maximum mile possible 
		if(site[count - 1] > total_miles ){
			cout<<"Site cannot be more than total miles!! Enter again..\n";
			count--;
			continue;
		}
		//any negative input will stop this loop
		if(site[count - 1] < 0)
			break;
		//testing whether sites are inserted in increasing order
		if( count>1 && site[count - 2] > site[count - 1] ){
			cout<<"Site can't be smaller than previous site!! Enter again..\n";
			count--;
			continue;	
		}
	}
	count--;
	for(int i=0;i<count;i++){
		cout<<"\nEnter revenue for site "<<site[i]<<" : ";
		cin>>revenue[i];
		if(revenue[i]<=0){
			cout<<"Revenue cannot be less than or equal to zero!! Enter again..\n";
			i--;
			continue;
		}
	} 
	cout<<"\n\nMaximum revenue : "<<maximumRevenue(total_miles, site, revenue, count)<<"\n"; 
	return 0; 
} 
