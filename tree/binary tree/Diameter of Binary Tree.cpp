/*
https://leetcode.com/problems/diameter-of-binary-tree/

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
    int maxdepth(TreeNode* root,int& res){
        if(root==NULL) return 0;
        int left=maxdepth(root->left,res);
        int right=maxdepth(root->right,res);
        res=max(res,left+right);
        return max(left,right)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        maxdepth(root,res);
        return res;
    }
};
