#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;
        return std::max(leftHeight, rightHeight) + 1;
    }
};

TreeNode *buildTree(std::vector<std::string> &nodes)
{
    if (nodes.empty())
        return nullptr;

    std::queue<TreeNode *> nodeQueue;
    TreeNode *root = new TreeNode(std::stoi(nodes[0]));
    nodeQueue.push(root);

    int i = 1;
    while (!nodeQueue.empty() && i < nodes.size())
    {
        TreeNode *currNode = nodeQueue.front();
        nodeQueue.pop();

        if (nodes[i] != "null")
        {
            currNode->left = new TreeNode(std::stoi(nodes[i]));
            nodeQueue.push(currNode->left);
        }
        i++;

        if (i >= nodes.size())
            break;

        if (nodes[i] != "null")
        {
            currNode->right = new TreeNode(std::stoi(nodes[i]));
            nodeQueue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void freeTree(TreeNode *root)
{
    if (root == nullptr)
        return;

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main()
{

    cout << "Enter the elements of the binary tree in level order (separated by space): ";
    string input;
    getline(std::cin, input);

    vector<string> nodes;
    stringstream ss(input);
    string item;
    while (getline(ss, item, ' '))
    {
        nodes.push_back(item);
    }

    // Build the binary tree from input
    TreeNode *root = buildTree(nodes);

    // Create an instance of the Solution class
    Solution solution;

    // Call the isBalanced function and print the result
    bool balanced = solution.isBalanced(root);
    if (balanced)
        std::cout << "The binary tree is balanced." << endl;
    else
        std::cout << "The binary tree is not balanced." << endl;

    // Free the memory allocated for the binary tree
    freeTree(root);
}


//Time complexity & Space complexity:- O(N)

//Question asked int:- Facebook, Adobe, Amazon, Microsoft