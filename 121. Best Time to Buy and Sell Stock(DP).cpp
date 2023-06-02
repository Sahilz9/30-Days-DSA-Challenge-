#include <bits/stdc++.h>
using namespace std;

int findProfit(vector<int> &prices)
{
    int mini = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int difference = prices[i] - mini;
        profit = max(profit, difference);
        mini = min(mini, prices[i]);
    }
    return profit;
}

int main()
{
    int n;
    cout << "Enter the number of an element:- ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the Elements:- ";
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    int ans = findProfit(prices);
    cout << ans << endl;
}

//Dynamic Programming
// Time Complexity:- O(N)
// Space Complexity:- O(1)