#include <bits/stdc++.h>
using namespace std;

bool isValid(char ch)
{
    if ((ch >= 'a' && ch < 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

char lowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(string s)
{
    int start = 0, end = s.length() - 1;
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}

int main()
{
    vector<string> s{"race", "a", "car"};
    int n = s.size();
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s[i].length(); j++)
        {
            if (isValid(s[i][j]))
            {
                temp.push_back(lowerCase(s[i][j]));
            }
        }
    }

    bool isPalindrome = checkPalindrome(temp);
    if (isPalindrome)
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }
}
//Time complexity is O(m + p)
//Space complexity is O(m)