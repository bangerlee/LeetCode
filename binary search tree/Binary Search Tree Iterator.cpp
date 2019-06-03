/*
https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator {
private:
    stack<TreeNode*> st;
    void pushnode(TreeNode* root){
        if(root==NULL) return;
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushnode(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* res=st.top();
        st.pop();
        if(res->right!=NULL) pushnode(res->right);
        return res->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
