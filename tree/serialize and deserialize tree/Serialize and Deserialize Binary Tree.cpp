/*
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

preorder  1 2 3 X X

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
    void sehelper(TreeNode* root,string& res){
        if(root==NULL){
            res+=" X ";
            return;
        }
        res+=" "+to_string(root->val)+" ";
        sehelper(root->left,res);
        sehelper(root->right,res);
        return;
    }
    TreeNode* dehelper(queue<string>& que){
        if(que.empty()) return NULL;
        string tmp=que.front();
        que.pop();
        if(tmp=="X") return NULL;
        else{
            TreeNode* root=new TreeNode(stoi(tmp));
            root->left=dehelper(que);
            root->right=dehelper(que);
            return root;
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        sehelper(root,res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> que;
        stringstream ss(data);
        string tmp;
        while(ss>>tmp) que.push(tmp);
        return dehelper(que);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
