/*
https://leetcode.com/problems/balanced-binary-tree/

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
    bool judgeBlanced(TreeNode* root,int& depth){
        if(root==0){depth=0; return true;}
        int left=0,right=0;
        bool lt=judgeBlanced(root->left,left);
        bool rt=judgeBlanced(root->right,right);
        if(lt&&rt&&abs(left-right)<=1){
            depth=max(left,right)+1;
            return true;
        }
        return false;
    }
public:
    bool isBalanced(TreeNode* root) {
        int depth=0;
        return judgeBlanced(root,depth);
    }
};
