#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(vector<int> &nums, int index, vector<int> output, vector<vector<int>> &ans)
    {
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        solve(nums, index + 1, output, ans);
        output.push_back(nums[index]);
        solve(nums, index + 1, output, ans);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, index, output, ans);
        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution solution;
    vector<vector<int>> result = solution.subsets(nums);

    cout << "Subsets:" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

//Time complexity:- O(2^N)
//Space complexity:- O(N*2^N)

//Question asked in:- Google, Facebooko, Adobe, Paypal
