#include<iostream>
#include<math.h>

using namespace std;

//data structure
struct license
{

	int license_no;             //to store license no.
	float growth_rate;          //rate of growth of its price
};

//functions
float amount(license arr[], int n)
{

	/*
	Objective:
	This function returns the total minimized amount to be spend to buy license

	Input variables
                    arr : array of objects of license type
                    n : number of objects in array arr

	Return value :None

	*/

	float amount  = 0;
	for(int i=0; i<n; i++){
		amount += pow(arr[i].growth_rate, i);
	}
	return amount*100;
}

int max_calc(license arr[], int n){

	/*
	Objective :	This function returns the license_no of software having maximum rate_of_growth value in l_arr.

	Input variables
            - arr : array of objects of license type
            - n : number of objects in array arr

	Return value: license number with maximum rate_of_growth

	*/

	//'maximum' stores the index of license with most expensive license growth rate in array l
	int maximum = 0;

	//traversing entire array to find most expensive license
	for(int i=1;i<n;i++){
		if(arr[i].growth_rate > arr[maximum].growth_rate)
			maximum = i;
	}

	//Now, max index has most expensive license in l_arr, so swap it with first license object of l_arr
	swap(arr[0].growth_rate, arr[maximum].growth_rate);
	swap(arr[0].license_no, arr[maximum].license_no);

	//return the license of first license object in array 'arr'
	return arr[0].license_no;
}

void print_order(license arr[], int n)
{
	/*
	Objective :This function finds and prints the order of buying license

	Input variable :
                -arr[] : array of objects of license type
                -n     : number of objects in array arr

    Return Values  : None

	*/

	for(int i=0; i<n; i++){

		//call to find maximum from the remaining array l[i..n-1]
		cout<<"License "<<max_calc((arr+i), n-i);
		cout<<"  : Rate "<<arr[i].growth_rate<<endl;
	}
}


//driver code
int main(){
	int number;
	cout<<"\t***SOFTWARE LICENSE PROBLEM***\n";

	while(true){
		cout<<"\n\nEnter number of cryptographic softwares : ";
		cin>>number;
		if(number>=1)		//number of software must be atleast 1
			break;
		else
			cout<<"\nNo. of softwares should be atleast 1!";
	}
	license *lic = new license[number];
	//input rate
	for(int i=0; i<number; i++){

		float gr;     // for growth rate
		cout<<"\n\nEnter rate of growth for license "<<i+1<<" : ";
		cin>>gr;

		if(gr <= 1){
			cout<<"\nrate must be greater than 1!";
			i--;
			continue;
		}
		lic[i].license_no = i+1;
		lic[i].growth_rate = gr;
	}

	cout<<"\n\nOrder of buying license is \n\n";
	print_order(lic, number);

	cout<<"\n\nMinimized amount is : $"<<amount(lic, number);

	return 0;
}
