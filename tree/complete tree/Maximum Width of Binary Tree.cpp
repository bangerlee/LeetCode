/*
https://leetcode.com/problems/maximum-width-of-binary-tree/

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
private:
    int helper(TreeNode* root,int level,unsigned int idx,vector<unsigned int>& v){
        if(root==NULL) return 0;
        if(level==v.size()) v.push_back(idx);
        int res=idx+1-v[level];
        int left=helper(root->left,level+1,idx*2,v);
        int right=helper(root->right,level+1,idx*2+1,v);
        return max(res,max(left,right));
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<unsigned int> v;
        return helper(root,0,1,v);
    }
};
