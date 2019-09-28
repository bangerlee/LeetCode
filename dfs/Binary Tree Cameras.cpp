/*
https://leetcode.com/problems/binary-tree-cameras/

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
    int res=0;
    int dfs(TreeNode* root){
        if(!root) return 2;
        int left=dfs(root->left), right=dfs(root->right);
        if(left==0 || right==0){
            res++;
            return 1;
        }
        return left==1 || right==1?2:0;
    }
public:
    int minCameraCover(TreeNode* root) {
        return (dfs(root)<1?1:0)+res;
    }
};
