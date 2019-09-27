/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* helper(int prestart,int instart,int inend,vector<int>& preorder,vector<int>& inorder){
        if(prestart>=preorder.size()||instart>inend) return NULL;
        TreeNode* node=new TreeNode(preorder[prestart]);
        int idx=0;
        for(int i=instart;i<=inend;i++){
            if(node->val==inorder[i]){
                idx=i;
                break;
            }
        }
        node->left=helper(prestart+1,instart,idx-1,preorder,inorder);
        node->right=helper(prestart+idx-instart+1,idx+1,inend,preorder,inorder);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0,0,inorder.size()-1,preorder,inorder);
    }
};
