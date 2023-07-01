#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        vector<int> count(128);
        int required = p.length();

        for (const char c : p)
            ++count[c];

        for (int l = 0, r = 0; r < s.length(); ++r)
        {
            if (--count[s[r]] >= 0)
                --required;
            while (required == 0)
            {
                if (r - l + 1 == p.length())
                    ans.push_back(l);
                if (++count[s[l++]] > 0)
                    ++required;
            }
        }

        return ans;
    }
};

int main()
{
    string s, p;
    cout << "Enter the string (s): ";
    cin >> s;
    cout << "Enter the pattern (p): ";
    cin >> p;

    // Create an instance of the Solution class
    Solution solution;

    // Call the findAnagrams function and get the result
    vector<int> result = solution.findAnagrams(s, p);

    cout << "Anagram indices: ";
    for (int index : result)
        cout << index << " ";
    cout << endl;
}

//Time:- O(n)
//Space:- O(26)

// Question:- Amazon, Salesforce, Paypal, Facebook 