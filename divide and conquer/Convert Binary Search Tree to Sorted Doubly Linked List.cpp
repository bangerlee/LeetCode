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
    Node* connect(Node* n1,Node* n2){
        if(n1==NULL) return n2;
        if(n2==NULL) return n1;
        Node* tail1=n1->left;
        Node* tail2=n2->left;
        tail1->right=n2;
        n2->left=tail1;
        tail2->right=n1;
        n1->left=tail2;
        
        return n1;
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(root==NULL) return NULL;
        Node* left=treeToDoublyList(root->left);
        Node* right=treeToDoublyList(root->right);
        root->left=root;
        root->right=root;
        return connect(connect(left,root),right);
    }
};
