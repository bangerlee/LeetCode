/*
https://leetcode.com/problems/closest-binary-search-tree-value/

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
    int closestValue(TreeNode* root, double target) {
        int res=root->val;
        while(root!=NULL){
            if(abs(res-target)>abs(root->val-target)){
                res=root->val;
            }
            root=root->val>target?root->left:root->right;
        }
        return res;
    }
};
