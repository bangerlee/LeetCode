/*
https://leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root->left,root->right});
        while(!q.empty()){
            pair<TreeNode*,TreeNode*> p=q.front();q.pop();
            if(!p.first && !p.second) continue;
            if(!p.first || !p.second) return false;
            if(p.first->val != p.second->val) return false;
            q.push({p.first->left,p.second->right});
            q.push({p.first->right,p.second->left});
        }
        return true;
    }
};
