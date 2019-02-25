/*
https://leetcode.com/problems/closest-binary-search-tree-value-ii/

BST inorder -> 有序序列
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
    void helper(TreeNode* root,vector<int>& res,double target,int k){
        if(root==NULL) return;
        helper(root->left,res,target,k);
        if(res.size()==k){
            if(abs(target-root->val)<abs(target-res[0]))
                res.erase(res.begin());
            else return;
        }
        res.push_back(root->val);
        helper(root->right,res,target,k);
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        helper(root,res,target,k);
        return res;
    }
};
