/*
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

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
    int find(TreeNode* root,unordered_map<TreeNode*,int>& m,TreeNode* target){
        if(root==NULL) return -1;
        if(root->val==target->val){
            m[root]=0;
            return 0;
        }
        int left=find(root->left,m,target);
        if(left>=0){
            m[root]=left+1;
            return left+1;
        }
        int right=find(root->right,m,target);
        if(right>=0){
            m[root]=right+1;
            return right+1;
        }
        return -1;
    }
    void helper(unordered_map<TreeNode*,int>& m,int K,vector<int>& res,TreeNode* root,int len){
        if(root==NULL) return;
        if(m.find(root)!=m.end()) len=m[root];
        if(len==K) res.push_back(root->val);
        helper(m,K,res,root->left,len+1);
        helper(m,K,res,root->right,len+1);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*,int> m;
        vector<int> res;
        find(root,m,target);
        helper(m,K,res,root,m[root]);
        return res;
    }
};
