#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// Helper function to build a binary tree from user input
TreeNode *buildTree()
{
    int val;
    cout << "Enter node value (or -1 for null): ";
    cin >> val;

    if (val == -1)
        return nullptr;

    TreeNode *root = new TreeNode(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main()
{
    TreeNode *root = buildTree();

    Solution solution;
    int depth = solution.maxDepth(root);

    cout << "Max Depth of the binary tree: " << depth << endl;
}

// Time:- O(n)
// Space:- O(1)

// Companies:- Google, Amazin, Microsoft, Paypal