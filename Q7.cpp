#include<iostream>
#include<algorithm>

using namespace std;

#define N 3         //number of days

int buy[N];         // to store the min price value seen so far at each day denoted by 'i'
int p[N]={9,1,5}  ;  // price per share at each day 'i'
int k ;              // loop counter variable
int profit[N];      // stores profit calculated at each day

int minBuyday()
{
    /*
    Objective : To find min value day seen so far .
    Input : None
    Return : Min day to buy shares
    */

    buy[0]=p[0];
    for (k=1;k<N;k++)
    {
        buy[k]=std::min(buy[k-1],p[k]);
    }
    return (std::distance(p, std::find(p, p + N, p[N])));  //returns the min price day where buying will happen
}


std::pair<int,int> profit_day()
{

    /*
    Objective : To compute profit at each day by selling shares .
    Input : None
    Return : Max Profit per share and day to sell shares-(as a pair)
    */

    profit[0]=0;            //sold first day only , not a possible case
    for (k=1;k<N;k++)
    {
                 //recurssive
        profit[k]=std::max(profit[k-1],(p[k]-buy[k]));

    }

    //returns the max profit value and the day at which selling shares yield max value of profit.
    return(std::make_pair(profit[N-1],std::distance(profit, std::find(profit, profit + N, profit[N-1]))));


}

//driver code
int main()
{
    cout<<"\t***Simulation Problem For N = "<<N<<"***"<<endl<<endl;;
    cout<<"Buying should happen at day "<< minBuyday()+1<<endl<<endl;
    std::pair<int,int> p = profit_day();
    cout<<"Selling should happen at "<<p.second<<" th day earning total profit "<<p.first+1<<" value per share\n";

    return 0;

}

