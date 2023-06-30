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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);

        if (l && r)
            return root;
        return l ? l : r;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *p = root->left;  // Node with value 5
    TreeNode *q = root->right; // Node with value 1

    Solution solution;
    TreeNode *ancestor = solution.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor: " << ancestor->val << endl;

    // Clean up the allocated memory
    // ... (delete the tree nodes)
}

// Time:- O(h)
// Space:- O(h)

// Companies:- Google, Adobe, Amazon, Salesforce