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
    vector<int> inOrderList;
    void inorderTraversalList(TreeNode* root) {
        if (!root)
            return;
        inorderTraversalList(root->left);
        inOrderList.push_back(root->val);
        inorderTraversalList(root->right);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraversalList(root);
        return inOrderList;
        
    }
};