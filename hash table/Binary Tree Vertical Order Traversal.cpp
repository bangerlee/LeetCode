/*
https://leetcode.com/problems/binary-tree-vertical-order-traversal/

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q;
        if(root) q.emplace(root,0);
        while(q.size()){
            auto node=q.front().first;
            int x=q.front().second;
            q.pop();
            m[x].push_back(node->val);
            if(node->left) q.emplace(node->left,x-1);
            if(node->right) q.emplace(node->right,x+1);
        }
        vector<vector<int>> res;
        for(auto p:m) res.push_back(p.second);
        return res;
    }
};
