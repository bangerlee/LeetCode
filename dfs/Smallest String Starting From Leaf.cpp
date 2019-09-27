/*
https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    string smallestFromLeaf(TreeNode* root) {
        if(root==NULL) return "|";
        string s=string(1,'a'+root->val);
        if(root->left==NULL&&root->right==NULL) return s;
        return min(smallestFromLeaf(root->left)+s,smallestFromLeaf(root->right)+s);
    }
};
