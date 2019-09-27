/*
https://leetcode.com/problems/binary-tree-coloring-game/

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
    int left,right,val;
    int count(TreeNode* node){
        if(!node) return 0;
        int l=count(node->left),r=count(node->right);
        if(node->val==val) left=l,right=r;
        return l+r+1;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val=x,n=count(root);
        return max(max(left,right),n-left-right-1) > n/2;
    }
};
