/*
https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* p=root;
        while(true){
            if(p->val<=val){
                if(p->right!=NULL) p=p->right;
                else{
                    p->right=new TreeNode(val);
                    break;
                }
            }
            else{
                if(p->left!=NULL) p=p->left;
                else{
                    p->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
