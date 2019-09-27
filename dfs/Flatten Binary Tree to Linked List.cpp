/*
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    TreeNode* flat(TreeNode* root,TreeNode* pre){
        if(root==NULL) return pre;
        pre=flat(root->right,pre);
        pre=flat(root->left,pre);
        root->right=pre;
        root->left=NULL;
        pre=root;
        return pre;
    }
public:
    void flatten(TreeNode* root) {
        flat(root,NULL);
    }
};
