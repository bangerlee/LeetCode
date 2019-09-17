/*
https://leetcode.com/problems/diameter-of-binary-tree/

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
    int helper(TreeNode* root,int& res){
        if(root==NULL) return 0;
        int left=helper(root->left,res);
        int right=helper(root->right,res);
        res=max(res,left+right);
        return max(left,right)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        helper(root,res);
        return res;
    }
};
