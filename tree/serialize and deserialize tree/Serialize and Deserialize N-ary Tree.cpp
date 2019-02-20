/*
https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/

root->val childrenNum children-val...
*/
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
private:
    void sehelper(Node* root,string& res){
        if(root==NULL) return;
        res+=" "+to_string(root->val)+" "+to_string(root->children.size());
        for(auto x:root->children) sehelper(x,res);
    }
    Node* dehelper(stringstream& ss){
        int val,childsize;
        if(ss>>val>>childsize){
            Node* root=new Node();
            root->val=val;
            for(int i=0;i<childsize;i++) root->children.push_back(dehelper(ss));
            return root;
        }
        return NULL;
    }
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res="";
        sehelper(root,res);
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        return dehelper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
