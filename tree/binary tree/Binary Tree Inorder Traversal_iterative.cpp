/*
https://leetcode.com/problems/binary-tree-inorder-traversal/

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root=root->left;
            }
            root=st.top();st.pop();
            res.push_back(root->val);
            root=root->right;
        }
        return res;
    }
};
