#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1 || edges.empty())
            return {0};

        vector<int> ans;
        unordered_map<int, unordered_set<int>> graph;

        for (const vector<int> &edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            graph[u].insert(v);
            graph[v].insert(u);
        }

        for (const auto &[label, children] : graph)
            if (children.size() == 1)
                ans.push_back(label);

        while (n > 2)
        {
            n -= ans.size();
            vector<int> nextLeaves;
            for (const int leaf : ans)
            {
                const int u = *graph[leaf].begin();
                graph[u].erase(leaf);
                if (graph[u].size() == 1)
                    nextLeaves.push_back(u);
            }
            ans = nextLeaves;
        }

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> edges(numEdges, vector<int>(2));
    cout << "Enter the edges (node u and node v): ";
    for (int i = 0; i < numEdges; ++i)
        cin >> edges[i][0] >> edges[i][1];

    // Create an instance of the Solution class
    Solution solution;

    // Call the findMinHeightTrees function and get the result
    vector<int> result = solution.findMinHeightTrees(n, edges);

    cout << "Min Height Trees: ";
    for (int node : result)
        cout << node << " ";
    cout << endl;
}

//Time:- O(n)
//Space:- O(n)

//Question:- Google, Paypal, Facebook, Adobe