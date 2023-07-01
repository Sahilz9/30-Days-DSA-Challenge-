#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // dp[i][j] := unique paths from (0, 0) to (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m - 1][n - 1];
    }
};

int main()
{
    // Read input from the user
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    // Create an instance of the Solution class
    Solution solution;

    // Call the uniquePaths function and get the result
    int result = solution.uniquePaths(m, n);

    cout << "Number of unique paths: " << result << endl;
}

// Time:- O(mn)
// Space:- O(mn)

// Question:- Google, Amazon, Adobe, Facebook