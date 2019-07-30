/*
https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

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
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL || root->left==NULL) return -1;
        int l=root->left->val==root->val?findSecondMinimumValue(root->left):root->left->val;
        int r=root->right->val==root->val?findSecondMinimumValue(root->right):root->right->val;
        return l==-1||r==-1?max(l,r):min(l,r);
    }
};
