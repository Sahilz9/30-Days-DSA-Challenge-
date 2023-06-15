#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int l = 0, m = 0, h = nums.size() - 1;
        while (m <= h)
        {
            if (nums[m] == 0)
            {
                swap(nums[l++], nums[m++]);
            }
            else if (nums[m] == 1)
            {
                m++;
            }
            else
            {
                swap(nums[m], nums[h--]);
            }
        }
    }
};

int main()
{
    Solution solution;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements (0, 1, or 2): ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Before sorting: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    solution.sortColors(nums);

    cout << "After sorting: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}
