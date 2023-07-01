#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        if (n == 0)
            return tasks.size();

        vector<int> count(26);

        for (const char task : tasks)
            ++count[task - 'A'];

        const int maxFreq = *max_element(count.begin(), count.end());
        // Put the most frequent task in the slot first
        const int maxFreqTaskOccupy = (maxFreq - 1) * (n + 1);
        // Get # of tasks with the same frequency as maxFreq,
        // we'll append them after maxFreqTaskOccupy
        const int nMaxFreq = count_if(count.begin(), count.end(), [maxFreq](int c)
                                      { return c == maxFreq; });
        // Max(
        //   the most frequent task is frequent enough to force some idle slots,
        //   the most frequent task is not frequent enough to force idle slots
        // )
        return max(maxFreqTaskOccupy + nMaxFreq, static_cast<int>(tasks.size()));
    }
};

int main()
{
    // Read input from the user
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int numTasks;
    cout << "Enter the number of tasks: ";
    cin >> numTasks;

    vector<char> tasks(numTasks);
    cout << "Enter the tasks: ";
    for (int i = 0; i < numTasks; ++i)
        cin >> tasks[i];

    // Create an instance of the Solution class
    Solution solution;

    // Call the leastInterval function and get the result
    int result = solution.leastInterval(tasks, n);

    cout << "Minimum intervals required: " << result << endl;
}

//Time:- O(|tasks|)
//Space:- O(26)

//Question:- Google, Amazon, Salesforce, Adobe
