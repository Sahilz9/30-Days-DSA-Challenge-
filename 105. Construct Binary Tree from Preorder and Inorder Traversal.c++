#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inToIndex;

    for (int i = 0; i < inorder.size(); ++i)
      inToIndex[inorder[i]] = i;

    return build(preorder, 0, preorder.size() - 1, inorder, 0,
                 inorder.size() - 1, inToIndex);
  }

 private:
  TreeNode* build(const vector<int>& preorder, int preStart, int preEnd,
                  const vector<int>& inorder, int inStart, int inEnd,
                  const unordered_map<int, int>& inToIndex) {
    if (preStart > preEnd)
      return nullptr;

    const int rootVal = preorder[preStart];
    const int rootInIndex = inToIndex.at(rootVal);
    const int leftSize = rootInIndex - inStart;

    TreeNode* root = new TreeNode(rootVal);
    root->left = build(preorder, preStart + 1, preStart + leftSize, inorder,
                       inStart, rootInIndex - 1, inToIndex);
    root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder,
                        rootInIndex + 1, inEnd, inToIndex);
    return root;
  }
};

// Utility function to print the binary tree (inorder traversal)
void printInorder(TreeNode* root) {
  if (root) {
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
  }
}

int main() {
  // Read input from the user
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;

  vector<int> preorder(n), inorder(n);
  cout << "Enter the preorder traversal: ";
  for (int i = 0; i < n; ++i)
    cin >> preorder[i];
  cout << "Enter the inorder traversal: ";
  for (int i = 0; i < n; ++i)
    cin >> inorder[i];

  // Create an instance of the Solution class
  Solution solution;

  // Call the buildTree function and get the result
  TreeNode* root = solution.buildTree(preorder, inorder);

  cout << "Inorder traversal of the built tree: ";
  printInorder(root);
  cout << endl;

  // Clean up the dynamically allocated memory
  // (Not shown in the original code, but it's good practice to avoid memory leaks)
  // You can define a function to delete the tree recursively
}


//Time:- O(n)
//Space:- O(n)

//Question:- Google, Amazon, Paypal, Microsoft
