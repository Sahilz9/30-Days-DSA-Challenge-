#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for (const vector<int> &interval : intervals)
            if (ans.empty() || ans.back()[1] < interval[0])
                ans.push_back(interval);
            else
                ans.back()[1] = max(ans.back()[1], interval[1]);

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the intervals (start and end points): " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    Solution solution;
    vector<vector<int>> mergedIntervals = solution.merge(intervals);

    cout << "Merged intervals:" << endl;
    for (const auto &interval : mergedIntervals)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }
}

// Time:- O(sort)
// Space:- O(n)

// Companies:- Amazon, Salesforce, Paypal, Facebook