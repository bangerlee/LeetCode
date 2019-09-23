/*
https://leetcode.com/problems/delete-nodes-and-return-forest/

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
    TreeNode* helper(TreeNode* node,bool is_root){
        if(node==NULL) return NULL;
        bool deleted=to_delete_set.count(node->val)>0?true:false;
        if(is_root && !deleted) res.push_back(node);
        node->left=helper(node->left, deleted);
        node->right=helper(node->right, deleted);
        return deleted?NULL:node;
    }
public:
    set<int> to_delete_set;
    vector<TreeNode*> res;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i:to_delete) to_delete_set.insert(i);
        helper(root,true);
        return res;
    }
};
