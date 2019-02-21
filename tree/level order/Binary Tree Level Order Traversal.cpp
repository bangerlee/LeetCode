/*
https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int cnt=q.size();
            vector<int> tmp;
            for(int i=0;i<cnt;i++){
                TreeNode* p=q.front();
                q.pop();
                tmp.push_back(p->val);
                if(p->left!=NULL) q.push(p->left);
                if(p->right!=NULL) q.push(p->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
