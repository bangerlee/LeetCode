/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while((root->val-p->val)*(root->val-q->val)>0){
            root=root->val>p->val?root->left:root->right;
        }
        return root;
    }
};
