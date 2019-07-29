/*
https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        while(root!=NULL||!st.empty()){
            if(root!=NULL){
                st.push(root);
                res.insert(res.begin(),root->val);
                root=root->right;
            }
            else{
                root=st.top()->left;
                st.pop();
            }
        }
        return res;
    }
};
