#include<iostream>
#include<stdio.h>

using namespace std;

int matrixMulCost(int arr[],int size)
{
	int m[size][size];           // stores multiplication costs
 
    for (int i=1; i<size; i++)
        m[i][i] = 0;    //number of multiplications are 0(zero) when there is only one matrix
 
    //Here L is chain length. It varies from length 2 to length n.
    for (int L=2; L < size; L++)
    {
        for (int i=1; i < size-L+1; i++)
        {
            int j = i+L-1;
            int min = 32767;  //assigning to maximum value
 
            for (int k= i; k <= j-1; k++)
            {
              int  q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if (q < min)
                {
                    min = q;    //if number of multiplications found less that number will be updated.
                }
            }
         m[i][j] = min;  
        }
    }
 
    return m[1][size-1];   //returning the final answer which is M[1][n]
}
int main()
{
	int no_mat;
	cout<<"\nEnter the number of matrices	:	";
	cin>>no_mat;
	int arr[20];
	int size = no_mat +1;    
	cout<<"\n\t Enter the dimension :	"  ;    
	for (int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	cout<<"\n\t Minimum number of multiplications is  :"<<matrixMulCost(arr,size);
	return 0;
}
