#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long> stack;
        const unordered_map<string, function<long(long, long)>> op{
            {"+", plus<long>()},
            {"-", minus<long>()},
            {"*", multiplies<long>()},
            {"/", divides<long>()}};

        for (const string &token : tokens)
            if (op.count(token))
            {
                const long b = stack.top();
                stack.pop();
                const long a = stack.top();
                stack.pop();
                stack.push(op.at(token)(a, b));
            }
            else
            {
                stack.push(stoi(token));
            }

        return stack.top();
    }
};

int main()
{
    int n;
    cout << "Enter the number of tokens: ";
    cin >> n;

    vector<string> tokens(n);
    cout << "Enter the tokens: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> tokens[i];
    }

    Solution solution;
    int result = solution.evalRPN(tokens);

    cout << "Result: " << result << endl;
}

// Time:- O(n)
// Space:- O(n)

// Companies:- Google, Adobe, Paypal, Facebook