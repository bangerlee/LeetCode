/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<TreeNode*> st;
        st.push_back(new TreeNode(pre[0]));
        for(int i=1,j=0;i<pre.size();i++){
            TreeNode* tmp=new TreeNode(pre[i]);
            while(st.back()->val==post[j]){
                st.pop_back();
                ++j;
            }
            if(st.back()->left==NULL) st.back()->left=tmp;
            else if(st.back()->right==NULL) st.back()->right=tmp;
            st.push_back(tmp);
        }
        return st[0];
    }
};
