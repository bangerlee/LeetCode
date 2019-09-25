/*
https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    void helper(TreeNode* root,vector<int>& res,int d){
        if(root==NULL) return;
        if(d==res.size()) res.push_back(root->val);
        else res[d]=max(res[d],root->val);
        helper(root->left,res,d+1);
        helper(root->right,res,d+1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(root,res,0);
        return res;
    }
};
