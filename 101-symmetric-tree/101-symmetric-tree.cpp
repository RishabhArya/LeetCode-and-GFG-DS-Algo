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
    bool isSymmetricTree(TreeNode* rootLeft, TreeNode* rootrRight){
        if(rootLeft == NULL && rootrRight == NULL)
            return true;
        if((rootLeft != NULL && rootrRight == NULL) || (rootLeft == NULL && rootrRight != NULL)) 
            return false;
        if(rootLeft->val != rootrRight->val)
            return false;
        return isSymmetricTree(rootLeft->left, rootrRight->right) && 
            isSymmetricTree(rootLeft->right, rootrRight->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
    return isSymmetricTree(root->left, root->right);
    }
};