/*
https://leetcode.com/problems/distribute-coins-in-binary-tree/

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
        if(root==NULL) return 0;
        int l=dfs(root->left,res);
        int r=dfs(root->right,res);
        res+=abs(l)+abs(r);
        return root->val+l+r-1;
    }
public:
    int distributeCoins(TreeNode* root) {
        int res=0;
        dfs(root,res);
        return res;
    }
};
