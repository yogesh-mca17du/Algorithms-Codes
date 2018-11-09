//	Question no. : 3 - Program to solve N-Queen Problem using backtracking


#include<iostream>
using namespace std;

bool queensafe(char **board, int n, int row, int col)
{
	//This function returns true, if there is no queen in the same row or same column or diagonal to the position board[row,col] , otherwise false
	//This function is called when "col" queens are already placed in columns from 0 to col -1. So we need to check only left side for attacking queens
	int i,j;
	for(i=0; i<col; i++)
		if(board[row][i]=='Q')			//test whether there is a queen in left side of the row 
			return false;
	for (i=row, j=col; i>=0 && j>=0; i--, j--)	//test whether there is a queen in left part of upper diagonal 
        	if (board[i][j]=='Q') 
            		return false;
	for (i=row, j=col; j>=0 && i<n; i++, j--)   //test whether there is a queen in left part of lower diagonal
	if (board[i][j]=='Q') 
	        	return false; 
  
	return true; 
} 

void printboard(char **board, int n)
{
	//This function print status of chessboard, places where queen is placed is represented by 'Q', all other places are represented by '-'
	 
	static int k = 1; 
	cout<<"\n\nSolution "<<k++<<" \n\n"; 
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<board[i][j]<<"  ";
		cout<<"\n";
	}
}


bool nqueen(char **board, int n, int x)
{	
	//base case: test whether all queens are placed 
	if(x==n)
	{
		printboard(board,n);		//if yes, then print the board and return true
		return true;
	}
	
	bool a = false;					//a represents whether a solution exist or not. Initially, it is assumed to be 'false'. 
	
	for(int i=0; i<n; i++)			//In column 'x', try placing queen in all rows one by one  
	{
		if(queensafe(board,n,i,x))
		{
			board[i][x]='Q';					//when the position board[i,x] is safe, place a Q 
			a=nqueen(board, n, x+1) || a;		//recursive call to place rest of the queens, also make 'a' true if this placement leads to solution 
			board[i][x]='-';					//If placing queen in board[i,x] doesn't lead to a solution, then remove queen from board[i,x] 
		}
	}
	
	//If queen can not be place in any row of 'x'th column then 'a' with contain false 
	return a;
}

int main()
{
	int n;
	cout<<"\n\n\t\t\tN QUEENS PROBLEM\n\n";
	cout<<"\nEnter value of N(no. of queens): ";
	cin>>n;
	//creating 2D array of NxN dimension dyanamically 
	char **board = new char*[n];
	for(int i=0; i<n; i++)
		board[i] = new char[n];
	//initially every block of NxN grid with a '-'
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			board[i][j]='-';
	//test whether it is possible to place N queens on a NxN chessboard
	if(nqueen(board,n,0)==false)
	{
		cout<<"\nNo solution exists";		//If not possible
	}	
	delete board;							//deallocating memory
return 0;
}
