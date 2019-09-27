/*
https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* pre=NULL;
        while(!st.empty()||root!=NULL){
            while(root!=NULL){
                st.push(root);
                root=root->left;
            }
            root=st.top();st.pop();
            if(pre!=NULL&&pre->val>=root->val) return false;
            pre=root;
            root=root->right;
        }
        return true;
    }
};
