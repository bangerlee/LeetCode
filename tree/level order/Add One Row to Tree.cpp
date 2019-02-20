/*
https://leetcode.com/problems/add-one-row-to-tree/

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==0||d==1){
            TreeNode* node=new TreeNode(v);
            d==1?node->left=root:node->right=root;
            return node;
        }
        if(root!=NULL&&d>=2){
            root->left=addOneRow(root->left,v,d>2?d-1:1);
            root->right=addOneRow(root->right,v,d>2?d-1:0);
        }
        return root;
    }
};
