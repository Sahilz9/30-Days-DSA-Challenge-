#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int ans = 0;
        int num = 0;
        int sign = 1;
        stack<int> stack{{sign}}; // Stack.top(): current env's sign

        for (const char c : s)
            if (isdigit(c))
                num = num * 10 + (c - '0');
            else if (c == '(')
                stack.push(sign);
            else if (c == ')')
                stack.pop();
            else if (c == '+' || c == '-')
            {
                ans += sign * num;
                sign = (c == '+' ? 1 : -1) * stack.top();
                num = 0;
            }

        return ans + sign * num;
    }
};

int main()
{
    Solution solution;
    string expression = "(1+(4+5+2)-3)+(6+8)";

    int result = solution.calculate(expression);
    cout << "Result: " << result << endl;
}

// Time:- O(n)
// Space:- O(n)

// Question:- Google, Amazon, Salesforce, Paypal, Microsoft, Facebook, Adobe