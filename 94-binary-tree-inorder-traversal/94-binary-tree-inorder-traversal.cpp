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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> treeStack;
        vector<int> inOrderTraversal;
        
        while(root||!treeStack.empty()){
            if(root!= NULL){
                treeStack.push(root);
                root = root -> left;
            }
            else{
                root = treeStack.top();
                treeStack.pop();
                inOrderTraversal.push_back(root->val);
                root = root -> right;
            }
        }
        return inOrderTraversal;
    }
};