/*
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

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
    void sehelper(TreeNode* node,string& res){
        if(node==NULL){
            res+=" X ";
            return;
        }
        res+=" "+to_string(node->val)+" ";
        sehelper(node->left,res);
        sehelper(node->right,res);
        
    }
    TreeNode* dehelper(queue<string>& q){
        if(q.empty()) return NULL;
        string tmp=q.front();q.pop();
        if(tmp=="X") return NULL;
        TreeNode* newnode=new TreeNode(stoi(tmp));
        newnode->left=dehelper(q);
        newnode->right=dehelper(q);
        return newnode;
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
        stringstream ss(data);
        string tmp="";
        queue<string> q;
        while(ss>>tmp) q.push(tmp);
        return dehelper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
