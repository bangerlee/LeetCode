/*
https://leetcode.com/problems/design-linked-list/

*/
class MyLinkedList {
private:
    struct ListNode{
        int val;
        ListNode* prev;
        ListNode* next;
    };
    ListNode* head;
    int len;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head=NULL;
        len=0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0 || index>=len)
            return -1;
        int i=0;
        ListNode* tmp=head;
        for(;i<index;i++){
            tmp=tmp->next;
        }
        return tmp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* tmp=new ListNode;
        tmp->val=val;
        tmp->prev=NULL;
        if(len==0){
            tmp->next=NULL;
        }
        else{
            tmp->next=head;
            head->prev=tmp;
        }
        head=tmp;
        len+=1;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* tmp=new ListNode;
        tmp->val=val;
        tmp->next=NULL;
        if(len==0){
            tmp->prev=NULL;
            head=tmp;
            len+=1;
            return;
        }
        ListNode* idx=head;
        while(idx->next!=NULL)
            idx=idx->next;
        idx->next=tmp;
        tmp->prev=idx;
        len+=1;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>len || index<0)
            return;
        if(index==len){
            addAtTail(val);
            return;
        }
        ListNode* tmp=new ListNode;
        ListNode* idx=head;
        tmp->val=val;
        int i=0;
        for(;i<index-1;i++){
            idx=idx->next;
        }
        tmp->next=idx->next;
        tmp->prev=idx;
        idx->next->prev=tmp;
        idx->next=tmp;
        len+=1;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0 || index>=len)
            return;
        ListNode* tmp=head;
        if(index==0){
            head=head->next;
            head->prev=NULL;
            delete tmp;
            len-=1;
            return;
        }
        int i=0;
        for(;i<index-1;i++){
            tmp=tmp->next;
        }
        ListNode* idx=tmp->next;
        tmp->next=idx->next;
        if(idx->next!=NULL)
            idx->next->prev=tmp;
        delete idx;
        len-=1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
