/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

dummy node + level traversal
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* tmp=new Node(0,NULL,NULL,NULL);
        Node* p=root;
        while(p!=NULL){
            Node* cur=tmp;
            while(p!=NULL){
                if(p->left!=NULL){
                    cur->next=p->left;
                    cur=cur->next;
                }
                if(p->right!=NULL){
                    cur->next=p->right;
                    cur=cur->next;
                }
                p=p->next;
            }
            p=tmp->next;
            tmp->next=NULL;
        }
        return root; 
    }
};
