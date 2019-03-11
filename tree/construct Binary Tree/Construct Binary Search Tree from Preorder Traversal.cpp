/*
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* helper(vector<int> po,int i=0){
        if(po.size()==0) return NULL;
        for(i=1;i<po.size()&&po[i]<po[0];i++);
        TreeNode* root=new TreeNode(po[0]);
        root->left=helper(vector<int>(begin(po)+1,begin(po)+i));
        root->right=helper(vector<int>(begin(po)+i,end(po)));
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder);
    }
};
