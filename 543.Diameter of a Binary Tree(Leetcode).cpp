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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        maxDepth(root, ans);
        return ans;
    }

private:
    int maxDepth(TreeNode *root, int &ans)
    {
        if (root == nullptr)
            return 0;

        const int l = maxDepth(root->left, ans);
        const int r = maxDepth(root->right, ans);
        ans = max(ans, l + r);
        return 1 + max(l, r);
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
    int diameter = solution.diameterOfBinaryTree(root);

    cout << "Diameter of the binary tree: " << diameter << endl;
}


//Time:- O(n)
//Space:- O(h)

//Companies:- Facebook, Adobe, Amazon, Microsoft