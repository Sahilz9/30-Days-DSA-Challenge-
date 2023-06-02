#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            // If opening bracket, push it to the stack
            // If closing bracket, check stack top and pop

            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {

                // For closing bracket
                if (!st.empty())
                {
                    char top = st.top();
                    if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    // If stack is empty
                    return false;
                }
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    string input;
    cout << "Enter a string containing brackets: ";
    getline(cin, input);

    Solution solution;
    if (solution.isValid(input))
    {
        cout << "The brackets are valid." << endl;
    }
    else
    {
        cout << "The brackets are not valid." << endl;
    }
}
