/*
https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
        left=left<0?0:left;
        right=right<0?0:right;
        res=max(res,left+right+root->val);
        return max(left,right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        helper(root,res);
        return res;
    }
};
