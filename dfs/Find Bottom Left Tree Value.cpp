/*
https://leetcode.com/problems/find-bottom-left-tree-value/

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
    void helper(TreeNode* node,int depth,int& height,int& res){
        if(!node) return;
        if(depth>height){
            res=node->val;
            height=depth;
        }
        helper(node->left,depth+1,height,res);
        helper(node->right,depth+1,height,res);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int bottomLeft=0,height=0;
        helper(root,1,height,bottomLeft);
        return bottomLeft;
    }
};
