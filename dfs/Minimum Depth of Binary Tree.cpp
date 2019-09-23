/*
https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        return (left==0||right==0)?left+right+1:min(left,right)+1;
    }
};
