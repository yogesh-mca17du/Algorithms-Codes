#include <iostream>

using namespace std;

int check(int c, int *arr, int beg, int end)
{
     /*
    Objective: the function checking whether 'c' is the majority element of all or not.
    Input Variables:
        c: variable returned from divideInput function
        *arr: input array
        beg: start of the array
        end: end of the array
    Return Value:
        true, if c is the majority element
        else, false
    */

    int cnt=0;

    for(int i=beg; i<=end; i++)
    {
        if(arr[i]%5==c%5)   //checking the equivalence of element c with all other elements
            cnt++;
    }
    if(cnt-1 > (beg+end)/2) //count -1 as, c itself is not included in this count, an element being equivalent to it own self
        return 1;
    else
        return 0;
}

int divideInput(int *arr, int beg, int end)
{
    /*
    Objective: the function aims at dividing the input into equal halves and finding whether any two elements taken at a time are equivalent or not.
    Input Variables:
        *arr: input array
        beg: start of the array
        end: end of the array
    Return Value:
        c, that is the majority element(if any)
        else, 0 symbolizing there isn't any majority element
    */
    
    int c, found, mid;

    if(beg==end)   //returning 0 since there is just 1 element in the set
        return 0;

    else if(beg+1==end)  //checking equivalence of two elements of a set
    {
        if(arr[beg]%5 == arr[end]%5)
            return arr[beg];
    }

    mid=(beg+end)/2;  //diving the input into 2 equal halves
    c=divideInput(arr,beg,mid);
    if(c)
    {
        found=check(c,arr,beg,end);  //functions checks if the number found equal is equivalent to the majority of numbers in the set
        if(found)
            return c; //returning the majority element
        else
            return 0;
    }
    else
    {
        c=divideInput(arr,mid+1,end);
        found=check(c,arr,beg,end);
        if(found)
            return c;
        else
            return 0;
    }
    return 0; //since no majority element is found returning 0
}

int main()
{
    int n, *arr, flag;

    cout<<"\nEnter the total number of the cards: ";
    cin>>n;

    cout<<"\nAssuming two cards are equivalent if the mod 5 of it's number is equal. Also, 0 is not a valid card number";
    cout<<"\nEnter the card numbers\n";

    arr = new int[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    flag=divideInput(arr,0,n-1); //using divide and conquer approach
    if(flag)
        cout<<"\nSet Found";
    else
        cout<<"\nSet Not Found";
}
