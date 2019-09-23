/*
https://leetcode.com/problems/symmetric-tree/

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
    bool helper(TreeNode* left,TreeNode* right){
        if(left==NULL||right==NULL) return left==right;
        if(left->val!=right->val) return false;
        return helper(left->left,right->right)&&helper(left->right,right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL||helper(root->left,root->right);
    }
};
