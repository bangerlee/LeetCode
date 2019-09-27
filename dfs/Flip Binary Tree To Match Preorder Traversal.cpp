/*
https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/

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
    vector<int> res;
    int i=0;
    bool helper(TreeNode* root,vector<int>& v){
        if(root==NULL) return true;
        if(root->val!=v[i++]) return false;
        if(root->left&&root->left->val!=v[i]){
            res.push_back(root->val);
            return helper(root->right,v)&&helper(root->left,v);
        }
        return helper(root->left,v)&&helper(root->right,v);
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        return helper(root,voyage)?res:vector<int>{-1};
    }
};
