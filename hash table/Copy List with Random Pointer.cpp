/*
https://leetcode.com/problems/copy-list-with-random-pointer/

*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*,Node*> m;
        Node* node=head;
        while(node!=NULL){
            m[node]=new Node(node->val,NULL,NULL);
            node=node->next;
        }
        node=head;
        while(node!=NULL){
            m[node]->next=m[node->next];
            m[node]->random=m[node->random];
            node=node->next;
        }
        return m[head];
    }
};
