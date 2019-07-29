/*
https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(root!=NULL){
            res.push_back(root->val);
            if(root->right!=NULL) st.push(root->right);
            root=root->left;
            if(root==NULL&&!st.empty()){
                root=st.top();
                st.pop();
            }
        }
        return res;
    }
};
