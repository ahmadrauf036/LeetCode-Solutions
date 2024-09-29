/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a 
different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. 
Note that buying on day 2 and selling on day 1 is not allowed because you must buy 
before you sell.

--> Find the minimum price that will be buy day.
--> Find the maximum price onwards buy day that will be sell day.
*/

#include <iostream>
#include <vector>
using namespace std;


void maxProfit(vector<int> prices)
{
    if(prices.empty())
        return;
    int buyDay=0,sellDay=0;
    for (int i = 1; i < prices.size(); i++)
    {
        if(prices[i]<prices[buyDay])
        {
            buyDay=i;
        }
    }
    sellDay=buyDay;
    for (int i = buyDay+1; i < prices.size(); i++)
    {
        if(prices[i]>prices[sellDay])
        {
            sellDay=i;
        }
    }
    if(prices[sellDay]-prices[buyDay]>0)
    {
        cout<<"Buy day: "<<buyDay+1<<" (Price: "<<prices[buyDay]<<")"<<endl
            <<"Sell day: "<<sellDay+1<<" (Price: "<<prices[sellDay]<<")"<<endl
            <<"Profit: "<<prices[sellDay]-prices[buyDay]<<endl;
    }
    else
        cout<<"No profit predicted."<<endl;

    
    
}

int main()
{
    vector<int> prices = {9,8,7,6,5,4};
    maxProfit(prices);
    return 0;
}