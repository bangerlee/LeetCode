/*
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head,Node* res=NULL) {
        if(!head) return res;
        head->next=flatten(head->child,flatten(head->next,res));
        if(head->next) head->next->prev=head;
        head->child=NULL;
        return head;
    }
};
