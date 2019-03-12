/*
https://leetcode.com/problems/split-bst/

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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> res(2,NULL);
        if(root==NULL) return res;
        if(root->val>V){
            res[1]=root;
            vector<TreeNode*> tmp=splitBST(root->left,V);
            root->left=tmp[1];
            res[0]=tmp[0];
        }else{
            res[0]=root;
            vector<TreeNode*> tmp=splitBST(root->right,V);
            root->right=tmp[0];
            res[1]=tmp[1];
        }
        return res;
    }
};
