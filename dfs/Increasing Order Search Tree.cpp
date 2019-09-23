/*
https://leetcode.com/problems/increasing-order-search-tree/

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
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode* node=NULL,*newcur;
        TreeNode* cur=root;
        stack<TreeNode*> st;
        while(cur||!st.empty()){
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();st.pop();
            if(node==NULL){
                node=new TreeNode(cur->val);
                newcur=node;
            }else{
                newcur->right=new TreeNode(cur->val);
                newcur=newcur->right;
            }
            cur=cur->right;
        }
        return node;
    }
};
