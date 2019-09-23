/*
https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    int maxDiff(TreeNode* root,int mn,int mx){
        if(root==NULL) return mx-mn;
        return max(maxDiff(root->left,min(mn,root->val),max(mx,root->val)),maxDiff(root->right,min(mn,root->val),max(mx,root->val)));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return maxDiff(root,INT_MAX,0);
    }
};
