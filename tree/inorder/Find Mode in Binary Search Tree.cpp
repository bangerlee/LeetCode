/*
https://leetcode.com/problems/find-mode-in-binary-search-tree/

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
    int pre=INT_MIN,curfrq=0,maxfrq=0;
    void inorder(TreeNode* root,vector<int>& res){
        if(root==NULL) return;
        inorder(root->left,res);
        if(pre==root->val) curfrq++;
        else curfrq=1;
        if(curfrq>maxfrq){
            res.clear();
            maxfrq=curfrq;
            res.push_back(root->val);
        }
        else if(curfrq==maxfrq) res.push_back(root->val);
        pre=root->val;
        inorder(root->right,res);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};
