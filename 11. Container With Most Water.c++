#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;

        while (l < r)
        {
            const int minHeight = min(height[l], height[r]);
            ans = max(ans, minHeight * (r - l));
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the heights: ";
    for (int i = 0; i < n; ++i)
        cin >> height[i];

    // Create an instance of the Solution class
    Solution solution;

    // Call the maxArea function and get the result
    int result = solution.maxArea(height);

    cout << "Maximum area of water: " << result << endl;
}

// Time:- O(1)
// Space:- O(1)

// Question:- Amazon, Salesforce, Paypal, Facebook