/*
https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size(),imax=INT_MIN;
            for(int i=0;i<size;i++){
                TreeNode* cur=q.front();q.pop();
                imax=max(imax,cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res.push_back(imax);
        }
        return res;
    }
};
