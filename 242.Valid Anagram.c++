#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> h(26);
        for (int i = 0; i < s.length(); i++)
            h[s[i] - 'a']++;

        for (int i = 0; i < t.length(); i++)
        {
            int x = --h[t[i] - 'a'];
            if (x < 0)
                return false;
        }
        return true;
    }
};

int main()
{
    string s, t;
    cout << "Enter the first string: ";
    cin >> s;
    cout << "Enter the second string: ";
    cin >> t;

    Solution solution;
    bool result = solution.isAnagram(s, t);

    if (result)
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are not anagrams." << endl;
}

//Time complexity:- O(n)
//Space complexity:- O(1)