/*
https://leetcode.com/problems/boundary-of-binary-tree/

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
    void getbound(TreeNode* root,vector<int>& res,bool lb,bool rb){
        if(root==NULL) return;
        if(lb) res.push_back(root->val);
        if(!lb&&!rb&&!root->left&&!root->right) res.push_back(root->val);
        getbound(root->left,res,lb,rb&&root->right==NULL);
        getbound(root->right,res,lb&&root->left==NULL,rb);
        if(rb) res.push_back(root->val);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if(root){
            res.push_back(root->val);
            getbound(root->left,res,true,false);
            getbound(root->right,res,false,true);
        }
        return res;
    }
};
