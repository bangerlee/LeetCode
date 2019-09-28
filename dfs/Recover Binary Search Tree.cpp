/*
https://leetcode.com/problems/recover-binary-search-tree/

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
    TreeNode* firstE=NULL;
    TreeNode* secondE=NULL;
    TreeNode* prvE=NULL;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(firstE==NULL&&(prvE==NULL||prvE->val>=root->val)) firstE=prvE;
        if(firstE!=NULL&&prvE->val>=root->val) secondE=root;
        prvE=root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        int tmp=firstE->val;
        firstE->val=secondE->val;
        secondE->val=tmp;
    }
};
