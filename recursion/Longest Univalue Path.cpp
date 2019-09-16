/*
https://leetcode.com/problems/longest-univalue-path/

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
    int dfs(TreeNode* root,int& res){
        int l=root->left?dfs(root->left,res):0;
        int r=root->right?dfs(root->right,res):0;
        int resl=root->left&&root->left->val==root->val?l+1:0;
        int resr=root->right&&root->right->val==root->val?r+1:0;
        res=max(res,resl+resr);
        return max(resl,resr);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int res=0;
        if(root) dfs(root,res);
        return res;
    }
};
