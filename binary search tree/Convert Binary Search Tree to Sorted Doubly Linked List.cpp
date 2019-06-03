/*
https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:
    void link(Node* root,Node*& prv){
        if(root==NULL) return;
        link(root->left,prv);
        prv->right=root;
        root->left=prv;
        prv=root;
        link(root->right,prv);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(root==NULL) return NULL;
        Node* dummpy=new Node(0,NULL,NULL);
        Node* prv=dummpy;
        link(root,prv);
        
        prv->right=dummpy->right;
        dummpy->right->left=prv;
        return dummpy->right;
    }
};
