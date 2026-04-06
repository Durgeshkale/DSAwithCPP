/* leetcode 121: best time to buy and sell stocks 
we are given with an array of prices of stock on the ith day
we have to buy a stock on one day and sell the stock on another day after the day of buying 
and we have to gain the maximum profit and if there is no maximum profit we have to return 0
 
our appraoch is  if we are selling it on the ith day we check the previous days where we can buy it on the mininmum price */

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int mini = prices[0];
    int profit = 0;

    for(int i = 1; i < prices.size(); i++) {
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, prices[i]);
    }

    return profit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices: ";
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << "Maximum profit is: " << maxProfit(prices) << endl;

    return 0;
}