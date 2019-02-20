/*
https://leetcode.com/problems/path-sum-ii/

BFS + backtracking
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
    void bkt(TreeNode* root,int sum,vector<vector<int>>& res,vector<int>& cur){
        if(root==NULL) return;
        cur.push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&root->val==sum)
            res.push_back(cur);
        else{
            bkt(root->left,sum-root->val,res,cur);
            bkt(root->right,sum-root->val,res,cur);
        }
        cur.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        bkt(root,sum,res,cur);
        return res;
    }
};
