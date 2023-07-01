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
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<int> ans;
        queue<TreeNode *> q{{root}};

        while (!q.empty())
        {
            const int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (i == size - 1)
                    ans.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    // Create an instance of the Solution class
    Solution solution;

    // Call the rightSideView function and get the result
    vector<int> result = solution.rightSideView(root);

    cout << "Right Side View: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the dynamically allocated memory
    // (Not shown in the original code, but it's good practice to avoid memory leaks)
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

// Time:- O(n)
// Space:- O(n)

// Question:- Amazon, Salesforce, Paypal, Facebook