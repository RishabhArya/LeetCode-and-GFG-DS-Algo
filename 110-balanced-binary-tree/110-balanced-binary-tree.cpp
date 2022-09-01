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
public:
    int isBalanced(TreeNode* root,bool &balanced) {
        if (!root) return -1;
        int leftHeight = 1 + isBalanced(root->left,balanced);
        int rightHeight = 1 + isBalanced(root->right,balanced);
        
        if(abs(leftHeight - rightHeight) > 1) balanced = false;
        
        return max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        isBalanced(root,balanced);
        return balanced;
    }
};