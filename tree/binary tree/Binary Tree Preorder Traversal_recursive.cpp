/*
https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    void helper(TreeNode* root,vector<int>& res){
        if(root==NULL) return;
        res.push_back(root->val);
        helper(root->left,res);
        helper(root->right,res);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }
};
