/*
https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode* root) {
        TreeNode* l=root;
        TreeNode* r=root;
        int hl=0,hr=0;
        while(l!=NULL){l=l->left; hl++;}
        while(r!=NULL){r=r->right; hr++;}
        if(hl==hr) return pow(2,hl)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
