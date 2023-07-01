#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int ans = 0;
        stack<int> stack;

        for (int i = 0; i <= heights.size(); ++i)
        {
            while (!stack.empty() &&
                   (i == heights.size() || heights[stack.top()] > heights[i]))
            {
                const int h = heights[stack.top()];
                stack.pop();
                const int w = stack.empty() ? i : i - stack.top() - 1;
                ans = max(ans, h * w);
            }
            stack.push(i);
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    // Example input: [2, 1, 5, 6, 2, 3]
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int largestArea = solution.largestRectangleArea(heights);

    cout << "Largest Rectangle Area: " << largestArea << endl;
}

// Time:- O(n)
// Space:- O(n)

// Question:- Google, Amazon, Salesforce, Paypal, Microsoft, Facebook, Adobe