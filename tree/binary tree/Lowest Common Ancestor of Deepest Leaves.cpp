/*
https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

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
class depTree{
public:
    int depth;
    TreeNode* lca;
    depTree(int d, TreeNode* n){
        depth=d;
        lca=n;
    }
};
class Solution {
private:
    depTree* findLCA(TreeNode* root){
        if(root==NULL) return new depTree(0, NULL);
        depTree* lres=findLCA(root->left);
        depTree* rres=findLCA(root->right);
        if(lres->depth==rres->depth) return new depTree(lres->depth+1, root);
        else return new depTree(max(rres->depth, lres->depth)+1, rres->depth>lres->depth?rres->lca:lres->lca);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depTree* res=findLCA(root);
        return res->lca;
    }
};
