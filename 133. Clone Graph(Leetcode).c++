#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node(int _val) : val(_val) {}
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        queue<Node *> q{{node}};
        unordered_map<Node *, Node *> map{{node, new Node(node->val)}};

        while (!q.empty())
        {
            Node *u = q.front();
            q.pop();
            for (Node *v : u->neighbors)
            {
                if (!map.count(v))
                {
                    map[v] = new Node(v->val);
                    q.push(v);
                }
                map[u]->neighbors.push_back(map[v]);
            }
        }

        return map[node];
    }
};

// Helper function to create a graph from its adjacency list representation
Node *createGraph(const vector<vector<int>> &adjList)
{
    unordered_map<int, Node *> nodes;

    for (const vector<int> &neighbors : adjList)
    {
        int val = neighbors[0];
        Node *node = new Node(val);
        nodes[val] = node;
    }

    for (const vector<int> &neighbors : adjList)
    {
        int val = neighbors[0];
        Node *node = nodes[val];
        for (int i = 1; i < neighbors.size(); ++i)
        {
            int neighborVal = neighbors[i];
            node->neighbors.push_back(nodes[neighborVal]);
        }
    }

    return nodes[adjList[0][0]];
}

// Helper function to print the graph in adjacency list representation
void printGraph(const Node *node, unordered_set<const Node *> &visited)
{
    if (visited.count(node))
        return;

    visited.insert(node);

    cout << "Node " << node->val << ": ";
    for (const Node *neighbor : node->neighbors)
    {
        cout << neighbor->val << " ";
    }
    cout << endl;

    for (const Node *neighbor : node->neighbors)
    {
        printGraph(neighbor, visited);
    }
}

int main()
{
    int n;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;

    vector<vector<int>> adjList(n);
    cout << "Enter the adjacency list representation of the graph:" << endl;
    for (int i = 0; i < n; ++i)
    {
        int val, numNeighbors;
        cout << "Node " << i + 1 << ": ";
        cin >> val >> numNeighbors;
        adjList[i].push_back(val);
        for (int j = 0; j < numNeighbors; ++j)
        {
            int neighborVal;
            cin >> neighborVal;
            adjList[i].push_back(neighborVal);
        }
    }

    Node *originalGraph = createGraph(adjList);

    Solution solution;
    Node *clonedGraph = solution.cloneGraph(originalGraph);

    unordered_set<const Node *> visited;
    cout << "Original Graph:" << endl;
    printGraph(originalGraph, visited);

    visited.clear();
    cout << "Cloned Graph:" << endl;
    printGraph(clonedGraph, visited);
}

// Time:- O(|V|+|E|)
// Space:- O(|V|+|E|)

// Companies:- Google, Amazon, Paypal, Microsoft