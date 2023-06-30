#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements in sorted order: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target element to search for: ";
    cin >> target;

    Solution solution;
    int result = solution.search(nums, target);
    if (result != -1)
    {
        cout << "Target element found at index: " << result << endl;
    }
    else
    {
        cout << "Target element not found in the array." << endl;
    }
}
// Time:- O(logn)
// Space:- O(1)

// Companies:- Google, Salesforce, Paypal, Microsoft