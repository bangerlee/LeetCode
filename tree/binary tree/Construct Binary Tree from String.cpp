/*
https://leetcode.com/problems/construct-binary-tree-from-string/

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
    TreeNode* helper(string& s,int& idx)
    {
        if(idx>=s.length()) return NULL;
        int start=idx;
        if(s[idx]=='-') idx++;
        while(isdigit(s[idx])) idx++;
        int num=stoi(s.substr(start,idx-start));
        TreeNode* node=new TreeNode(num);
        if(s[idx]=='('){
            node->left=helper(s,++idx);
            ++idx;
        }
        if(s[idx]=='('){
            node->right=helper(s,++idx);
            ++idx;
        }
        return node;
    }
public:
    TreeNode* str2tree(string s) {
        if(s.length()==0) return NULL;
        int i=0;
        return helper(s,i);
    }
};
