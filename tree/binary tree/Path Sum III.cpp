/*
https://leetcode.com/problems/path-sum-iii/

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
    int sumup(TreeNode* root,int pre,int sum){
        if(root==NULL) return 0;
        int cur=pre+root->val;
        return (cur==sum)+sumup(root->left,cur,sum)+sumup(root->right,cur,sum);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        return sumup(root,0,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};
