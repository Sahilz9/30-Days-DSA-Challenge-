#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int ans = 0;
        vector<int> count(128);

        for (const char c : s)
            ++count[c];

        for (const int c : count)
            ans += c % 2 == 0 ? c : c - 1;

        const bool hasOddCount =
            any_of(count.begin(), count.end(), [](int c)
                   { return c & 1; });

        return ans + hasOddCount;
    }
};

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    Solution solution;
    int longestPal = solution.longestPalindrome(input);
    cout << "Longest Palindrome Length: " << longestPal << endl;
}

//Time:- O(n)
//Space:- O(1)

//Companies:- Paypal, Facebook, Amazon, Salesforce