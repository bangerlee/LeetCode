/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
        while(k!=0){
            TreeNode* tmp=st.top();
            st.pop();
            k--;
            if(k==0) return tmp->val;
            tmp=tmp->right;
            while(tmp!=NULL){
                st.push(tmp);
                tmp=tmp->left;
            }
        }
        return -1;
    }
};
