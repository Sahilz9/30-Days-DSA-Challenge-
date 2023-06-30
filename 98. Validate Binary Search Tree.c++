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
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, nullptr, nullptr);
    }

private:
    bool isValidBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
    {
        if (root == nullptr)
            return true;
        if (minNode && root->val <= minNode->val)
            return false;
        if (maxNode && root->val >= maxNode->val)
            return false;

        return isValidBST(root->left, minNode, root) &&
               isValidBST(root->right, root, maxNode);
    }
};

TreeNode *createNode(int val)
{
    TreeNode *node = new TreeNode(val);
    return node;
}

TreeNode *createTree(vector<int> &nodes, int i)
{
    if (i >= nodes.size() || nodes[i] == -1)
        return nullptr;

    TreeNode *root = createNode(nodes[i]);
    root->left = createTree(nodes, 2 * i + 1);
    root->right = createTree(nodes, 2 * i + 2);

    return root;
}

int main()
{
    Solution solution;

    cout << "Enter the tree nodes (-1 for null): ";
    vector<int> nodes;
    int val;
    while (cin >> val)
    {
        nodes.push_back(val);
        if (cin.peek() == '\n')
            break;
    }

    TreeNode *root = createTree(nodes, 0);

    bool isValid = solution.isValidBST(root);
    if (isValid)
        cout << "The tree is a valid binary search tree." << endl;
    else
        cout << "The tree is not a valid binary search tree." << endl;
}

// Time:- O(n)
// Space:- O(h)

// Companies:- Google, Adobe, Amazon, Salesforce,