/*
https://leetcode.com/problems/binary-tree-right-side-view/

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
    void rightview(TreeNode* root,vector<int>& res,int depth){
        if(root==NULL) return;
        if(depth==res.size())
            res.push_back(root->val);
        rightview(root->right,res,depth+1);
        rightview(root->left,res,depth+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightview(root,res,0);
        return res;
    }
};
