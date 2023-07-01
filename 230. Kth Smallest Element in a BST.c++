#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> stack;

        while (root)
        {
            stack.push(root);
            root = root->left;
        }

        for (int i = 0; i < k - 1; ++i)
        {
            root = stack.top(), stack.pop();
            root = root->right;
            while (root)
            {// Function to build a binary tree from an array representation
                stack.push(root);
                root = root->left;
            }
        }

        return stack.top()->val;
    }
};

// Function to build a binary tree from an array representation
TreeNode *buildTree(const vector<int> &nodes, int index)
{
    TreeNode *root = nullptr;
    if (index < nodes.size())
    {
        if (nodes[index] == -1)
            return nullptr;
        root = new TreeNode(nodes[index]);
        root->left = buildTree(nodes, 2 * index + 1);
        root->right = buildTree(nodes, 2 * index + 2);
    }
    return root;
}

int main()
{
    vector<int> nodes = {3, 1, 4, -1, 2};
    int k = 1;

    TreeNode *root = buildTree(nodes, 0);
    Solution solution;
    int result = solution.kthSmallest(root, k);
    cout << "The kth smallest element is: " << result << endl;
}

// Approach:- Stack

// Time:- O(n)
// Space:- O(h)

// Question:- Google, Salesforce, Paypal, Microsoft