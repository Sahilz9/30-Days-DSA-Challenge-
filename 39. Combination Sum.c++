#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, {}, ans);
        return ans;
    }

private:
    void dfs(const vector<int> &A, int s, int target, vector<int> &&path,
             vector<vector<int>> &ans)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }

        for (int i = s; i < A.size(); ++i)
        {
            path.push_back(A[i]);
            dfs(A, i, target - A[i], move(path), ans);
            path.pop_back();
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of candidates: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> candidates[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    Solution solution;
    vector<vector<int>> result = solution.combinationSum(candidates, target);

    cout << "Combinations that sum up to the target:" << endl;
    for (const auto &combination : result)
    {
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Time:- O(|candidate|^target)
// Space:- O(target)

// Companies:- Google, Adobe, Paypal, Facebook