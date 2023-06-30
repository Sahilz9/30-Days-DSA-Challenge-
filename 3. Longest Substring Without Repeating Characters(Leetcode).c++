#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        vector<int> count(128);

        for (int l = 0, r = 0; r < s.length(); ++r)
        {
            ++count[s[r]];
            while (count[s[r]] > 1)
                --count[s[l++]];
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    Solution solution;
    int longestSubstringLength = solution.lengthOfLongestSubstring(input);

    cout << "Length of the longest substring: " << longestSubstringLength << endl;
}

//Sliding Window Approach

//Time:- O(n)
//Space:- O(1)

//Companies:- Google, Adobe, Amazon, Salesforce