#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int index)
    {
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            solve(nums, ans, index + 1);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};

int main()
{
    Solution solution;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> permutations = solution.permute(nums);

    cout << "Permutations: " << endl;
    for (const auto &permutation : permutations)
    {
        for (const auto &num : permutation)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
