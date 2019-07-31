/*
https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

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
    TreeNode* recoverFromPreorder(string S) {
        vector<TreeNode*> st;
        for(int i=0,val,level;i<S.length();){
            for(level=0;S[i]=='-';i++) ++level;
            for(val=0;i<S.length()&&S[i]!='-';i++){
                val=val*10+S[i]-'0';
            }
            TreeNode* node=new TreeNode(val);
            while(st.size()>level) st.pop_back();
            if(!st.empty()){
                if(!st.back()->left) st.back()->left=node;
                else st.back()->right=node;
            }
            st.push_back(node);
        }
        return st[0];
    }
};
