#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    void push(int x)
    {
        if (stack.empty())
            stack.emplace(x, x);
        else
            stack.emplace(x, min(x, stack.top().second));
    }

    void pop()
    {
        stack.pop();
    }

    int top()
    {
        return stack.top().first;
    }

    int getMin()
    {
        return stack.top().second;
    }

private:
    stack<pair<int, int>> stack; // {x, min}
};

int main()
{
    MinStack minStack;

    cout << "Enter the number of operations: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cout << "Enter operation (push, pop, top, getMin): ";
        string operation;
        cin >> operation;

        if (operation == "push")
        {
            cout << "Enter value to push: ";
            int x;
            cin >> x;
            minStack.push(x);
        }
        else if (operation == "pop")
        {
            minStack.pop();
        }
        else if (operation == "top")
        {
            int top = minStack.top();
            cout << "Top element: " << top << endl;
        }
        else if (operation == "getMin")
        {
            int min = minStack.getMin();
            cout << "Minimum element: " << min << endl;
        }
    }
}

// Time:- O(1)
// Space:- O(n)

// Companies:- Adobe, Amazon, Facebook, Microsoft