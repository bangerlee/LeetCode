/*
https://leetcode.com/problems/univalued-binary-tree/

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
    bool traverse(TreeNode* p,int val){
        if(p->val!=val) return false;
        if(p->left!=NULL&&!traverse(p->left,val)) return false;
        if(p->right!=NULL&&!traverse(p->right,val)) return false;
        return true;
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return true;
        return traverse(root,root->val);
    }
};
