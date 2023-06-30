#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i + 2 < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // Choose nums[i] as the first num in the triplet,
            // and search the remaining nums in [i + 1, n - 1]
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                const int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[l++], nums[r--]});
                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                    while (l < r && nums[r] == nums[r + 1])
                        --r;
                }
                else if (sum < 0)
                {
                    ++l;
                }
                else
                {
                    --r;
                }
            }
        }

        return ans;
    }
};

// Helper function to print the vector of vectors
void printResult(const vector<vector<int>> &result)
{
    for (const vector<int> &triplet : result)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);

    cout << "Triplets with sum 0:" << endl;
    printResult(result);
}

// Time:- O(n^2)
// Space:- O(ans)

// Companies:- Adobe, Amazon, Facebook, Microsoft