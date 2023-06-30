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
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr)
      return {};

    vector<vector<int>> ans;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      vector<int> currLevel;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* node = q.front();
        q.pop();
        currLevel.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(currLevel);
    }

    return ans;
  }
};

// Helper function to create a binary tree from its level order traversal
TreeNode* createTree(const vector<int>& nodes, int i) {
  if (i >= nodes.size() || nodes[i] == -1)
    return nullptr;

  TreeNode* root = new TreeNode(nodes[i]);
  root->left = createTree(nodes, 2 * i + 1);
  root->right = createTree(nodes, 2 * i + 2);
  return root;
}

// Helper function to print the level order traversal
void printLevelOrder(const vector<vector<int>>& levelOrder) {
  cout << "Level Order Traversal:" << endl;
  for (const vector<int>& level : levelOrder) {
    for (int node : level) {
      cout << node << " ";
    }
    cout << endl;
  }
}

int main() {
  int n;
  cout << "Enter the number of nodes in the binary tree: ";
  cin >> n;

  vector<int> nodes(n);
  cout << "Enter the nodes of the binary tree (enter -1 for null nodes):" << endl;
  for (int i = 0; i < n; ++i) {
    cin >> nodes[i];
  }

  TreeNode* root = createTree(nodes, 0);

  Solution solution;
  vector<vector<int>> levelOrder = solution.levelOrder(root);

  printLevelOrder(levelOrder);
}


//Time:- O(n)
//Space:- O(n)

//Companies:- Google, Salesforce, Paypal, Microsoft