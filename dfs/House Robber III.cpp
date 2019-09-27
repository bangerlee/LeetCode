/*
https://leetcode.com/problems/house-robber-iii/

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
    int tryrob(TreeNode* root,int& l,int& r){
        if(root==NULL) return 0;
        int lr=0,rr=0,ll=0,rl=0;
        l=tryrob(root->left,ll,lr);
        r=tryrob(root->right,rl,rr);
        return max(root->val+ll+lr+rr+rl,l+r);
    }
public:
    int rob(TreeNode* root) {
        int l,r;
        return tryrob(root,l,r);
    }
};
