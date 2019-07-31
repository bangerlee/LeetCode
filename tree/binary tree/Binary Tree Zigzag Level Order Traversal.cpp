/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    void helper(TreeNode* root,vector<vector<int>>& res,int level){
        if(root==NULL) return;
        if(res.size()<=level) res.push_back(vector<int>(0));
        if(level%2==0) res[level].push_back(root->val);
        else res[level].insert(res[level].begin(),root->val);
        helper(root->left,res,level+1);
        helper(root->right,res,level+1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root,res,0);
        return res;
    }
};
