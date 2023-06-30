#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    string a, b;

    cout << "Enter the first binary string: ";
    cin >> a;

    cout << "Enter the second binary string: ";
    cin >> b;

    Solution solution;
    string result = solution.addBinary(a, b);

    cout << "Result: " << result << endl;
}

//Time:- O(max(|a|, |b|))
//Space:- O(max(|a|, |b|))

//Companies:- Google, Amazon, Microsoft, Paypal
