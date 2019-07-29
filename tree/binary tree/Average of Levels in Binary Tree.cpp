/*
https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        if(root==NULL) return res;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            double sum=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();q.pop();
                sum+=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            res.push_back(sum/size);
        }
        return res;
    }
};
