/*
https://leetcode.com/problems/path-sum-ii/

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
    void helper(TreeNode* root,vector<vector<int>>& res,vector<int>& cur,int sum){
        if(root==NULL) return;
        cur.push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&sum==root->val)
            res.push_back(cur);
        else{
            helper(root->left,res,cur,sum-root->val);
            helper(root->right,res,cur,sum-root->val);
        }
        cur.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(root,res,cur,sum);
        return res;
    }
};
