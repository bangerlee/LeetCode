/*
https://leetcode.com/problems/binary-tree-paths/

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
    void helper(TreeNode* root,string path,vector<string>& res){
        if(root->left==NULL&&root->right==NULL) res.push_back(path+to_string(root->val));
        if(root->left!=NULL) helper(root->left,path+to_string(root->val)+"->",res);
        if(root->right!=NULL) helper(root->right,path+to_string(root->val)+"->",res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==NULL) return res;
        helper(root,"",res);
        return res;
    }
};
