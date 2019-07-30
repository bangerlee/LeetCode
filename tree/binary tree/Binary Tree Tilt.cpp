/*
https://leetcode.com/problems/binary-tree-tilt/

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
    int helper(TreeNode* root,int& sum){
        if(root==NULL) return 0;
        int left=helper(root->left,sum);
        int right=helper(root->right,sum);
        sum+=abs(left-right);
        return left+right+root->val;
    }
public:
    int findTilt(TreeNode* root) {
        int sum=0;
        helper(root,sum);
        return sum;
    }
};
