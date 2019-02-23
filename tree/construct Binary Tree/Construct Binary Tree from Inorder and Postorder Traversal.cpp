/*
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* helper(int ppos,int instart,int inend,vector<int>& inorder,vector<int>& postorder){
        if(instart>inend||ppos<0) return NULL;
        TreeNode* node=new TreeNode(postorder[ppos]);
        int idx=0;
        for(int i=instart;i<=inend;i++){
            if(node->val==inorder[i]){
                idx=i;
                break;
            }
        }
        node->left=helper(ppos-1-(inend-idx),instart,idx-1,inorder,postorder);
        node->right=helper(ppos-1,idx+1,inend,inorder,postorder);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(postorder.size()-1,0,inorder.size()-1,inorder,postorder);
    }
};
