/*
https://leetcode.com/problems/find-leaves-of-binary-tree/

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
    int dfs(TreeNode* root,vector<vector<int>>& res){
        if(root==NULL) return 0;
        int level=max(dfs(root->left,res),dfs(root->right,res))+1;
        if(level>res.size()) res.push_back(vector<int>());
        res[level-1].push_back(root->val);
        return level;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root,res);
        return res;
    }
};
