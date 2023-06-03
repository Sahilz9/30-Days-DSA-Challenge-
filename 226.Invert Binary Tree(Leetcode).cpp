/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void swap(TreeNode* curr){
        if(!curr) //If current node is NULL then simply return
            return;
        swap(curr->left);
        swap(curr->right);

        //Swap the child pointer
        TreeNode* temp = curr->left;
        curr->left=curr->right;
        curr->right=temp;


    }
public:
    TreeNode* invertTree(TreeNode* root) {
        swap(root); //Create mirror image
        return root;
        
    }
};

//The time complexity of the above program is O(n), 
//where n is the number of nodes in the binary tree. 
//This is because the program visits each node exactly once during the inversion process. 
//The `swap` function is called recursively on each node, but the total number of recursive calls is proportional to the number of nodes in the tree.

//The space complexity of the program is O(h), 
//where h is the height of the binary tree. 
//This is because the space required by the program depends on the maximum number of function calls on the call stack at any given time, 
//which is equal to the height of the tree. In the worst case, 
//where the binary tree is skewed and has a height of n, the space complexity would be O(n). 
//However, in a balanced binary tree, the height is typically O(log n), resulting in a space complexity of O(log n).

//Question asked in:- Facebook, Adobe, Amazon, Microsoft