/*
https://leetcode.com/problems/cousins-in-binary-tree/

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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            bool isX=false,isY=false;
            for(int i=0;i<size;i++){
                TreeNode* cur=q.front();q.pop();
                if(cur->val==x) isX=true;
                if(cur->val==y) isY=true;
                if(cur->left!=NULL && cur->right!=NULL){
                    if(cur->left->val==x && cur->right->val==y) return false;
                    if(cur->left->val==y && cur->right->val==x) return false;
                }
                if(cur->left!=NULL) q.push(cur->left);
                if(cur->right!=NULL) q.push(cur->right);
            }
            if(isX && isY) return true;
        }
        return false;
    }
};
