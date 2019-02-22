/*
https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

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
    void helper(int& res,TreeNode*& root,int cur,int target){
        if(root==NULL) return;
        if(root->val==target) cur++;
        else cur=1;
        res=max(res,cur);
        helper(res,root->left,cur,root->val+1);
        helper(res,root->right,cur,root->val+1);
    }
public:
    int longestConsecutive(TreeNode* root) {
        int res=INT_MIN,cur=0;
        if(root==NULL) return 0;
        helper(res,root,cur,root->val);
        return res;
    }
};
