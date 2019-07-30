/*
https://leetcode.com/problems/construct-string-from-binary-tree/

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
    string tree2str(TreeNode* t) {
        if(t==NULL) return "";
        string res=to_string(t->val);
        string left=tree2str(t->left);
        string right=tree2str(t->right);
        if(left==""&&right=="") return res;
        if(left=="") return res+"()"+"("+right+")";
        if(right=="") return res+"("+left+")";
        return res+"("+left+")"+"("+right+")";
    }
};
