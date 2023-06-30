#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        auto compare = [&](const vector<int> &a, const vector<int> &b)
        {
            return squareDist(a) < squareDist(b);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxHeap(
            compare);

        for (const vector<int> &point : points)
        {
            maxHeap.push(point);
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        while (!maxHeap.empty())
        {
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return ans;
    }

private:
    int squareDist(const vector<int> &p)
    {
        return p[0] * p[0] + p[1] * p[1];
    }
};

// Helper function to print the vector of points
void printPoints(const vector<vector<int>> &points)
{
    for (const vector<int> &point : points)
    {
        cout << "(" << point[0] << ", " << point[1] << ") ";
    }
    cout << endl;
}

int main()
{
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    cout << "Enter the points (x, y):" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> points[i][0] >> points[i][1];
    }

    Solution solution;
    vector<vector<int>> closestPoints = solution.kClosest(points, k);

    cout << "K Closest Points: ";
    printPoints(closestPoints);
}

//Time:- O(n log K)
//Space:- O(K)

//Companies:- Google, Adobe, Amazon, Salesforce
