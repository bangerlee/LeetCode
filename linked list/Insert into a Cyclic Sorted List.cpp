/*
https://leetcode.com/problems/insert-into-a-cyclic-sorted-list/

*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head==NULL){
            Node* res=new Node(insertVal,NULL);
            res->next=res;
            return res;
        }
        bool inserted=false;
        Node* prev=head;
        Node* next=head->next;
        while(true){
            if((prev->val<=insertVal&&insertVal<=next->val)||
              (insertVal>prev->val&&prev->val>next->val)||
              (prev->val>next->val&&next->val>insertVal)){
                prev->next=new Node(insertVal,next);
                inserted=true;
                break;
            }
            prev=prev->next;
            next=next->next;
            if(prev==head) break;
        }
        if(inserted==false)
            prev->next=new Node(insertVal,next);
        return head;
    }
};
