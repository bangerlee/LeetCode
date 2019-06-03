/*
https://leetcode.com/problems/delete-node-in-a-bst/

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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val>key) root->left=deleteNode(root->left,key);
        else if(root->val<key) root->right=deleteNode(root->right,key);
        else{
            if(root->left==NULL) return root->right;
            if(root->right==NULL) return root->left;
            TreeNode* p=root->right;
            while(p->left!=NULL) p=p->left;
            p->left=root->left;
            return root->right;
        }
        return root;
    }
};
