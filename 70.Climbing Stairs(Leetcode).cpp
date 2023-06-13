#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int prev1 = 1;
        int prev2 = 1;

        for (int i = 2; i <= n; i++)
        {
            const int dp = prev1 + prev2;
            prev2 = prev1;
            prev1 = dp;
        }

        return prev1;
    }
};

int main()
{
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;

    Solution solution;
    int distinctWays = solution.climbStairs(n);

    cout << "The number of distinct ways to climb " << n << " steps: " << distinctWays << endl;
}

// Time complexity:- O(N)
// Space complexity:- O(1)

// Question asked in:- Goole, Amazon, Microsoft, Paypal
