/*
https://leetcode.com/problems/serialize-and-deserialize-bst/

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
class Codec {
private:
    TreeNode* getNode(queue<int>& que){
        if(que.empty()) return NULL;
        TreeNode* node=new TreeNode(que.front());
        que.pop();
        queue<int> smallque;
        while(!que.empty()&&que.front()<node->val){
            smallque.push(que.front());
            que.pop();
        }
        node->left=getNode(smallque);
        node->right=getNode(que);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        stack<TreeNode*> st;
        string res="";
        st.push(root);
        while(!st.empty()){
            TreeNode* p=st.top();
            res=res+to_string(p->val)+" ";
            st.pop();
            if(p->right!=NULL) st.push(p->right);
            if(p->left!=NULL) st.push(p->left);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
        stringstream ss(data);
        string tmp;
        queue<int> q;
        while(ss>>tmp) q.push(stoi(tmp));
        return getNode(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
