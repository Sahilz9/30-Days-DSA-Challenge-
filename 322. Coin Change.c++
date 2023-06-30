#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (const int coin : coins)
        {
            for (int i = coin; i <= amount; ++i)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main()
{
    Solution solution;

    cout << "Enter the number of coins: ";
    int n;
    cin >> n;

    cout << "Enter the coin values: ";
    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }

    cout << "Enter the amount: ";
    int amount;
    cin >> amount;

    int result = solution.coinChange(coins, amount);
    cout << "Fewest number of coins needed: " << result << endl;
}

// Time:- O(|coins||amount|)
// Space:- O(|amount|)

// Companies:- Adobe, Amazon, Facebook, Microsoft