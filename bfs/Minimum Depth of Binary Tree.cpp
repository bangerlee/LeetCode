/*
https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        int res=0;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            res++;
            int level=q.size();
            for(int i=0;i<level;i++){
                TreeNode* cur=q.front();q.pop();
                if(cur->left==NULL && cur->right==NULL) return res;
                if(cur->left!=NULL) q.push(cur->left);
                if(cur->right!=NULL) q.push(cur->right);
            }
        }
        return res;
    }
};
