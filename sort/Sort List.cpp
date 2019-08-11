/*
https://leetcode.com/problems/sort-list/

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* merge(ListNode* L1,ListNode* L2){
        ListNode* l=new ListNode(0),* p=l;
        while(L1!=NULL&&L2!=NULL){
            if(L1->val<L2->val){
                p->next=L1;
                L1=L1->next;
            }
            else{
                p->next=L2;
                L2=L2->next;
            }
            p=p->next;
        }
        if(L1!=NULL) p->next=L1;
        if(L2!=NULL) p->next=L2;
        return l->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        
        //break two halves
        ListNode* prev,*fast=head,*slow=head;
        while(fast!=NULL&&fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        
        //sort
        ListNode* L1=sortList(head);
        ListNode* L2=sortList(slow);
        
        return merge(L1,L2);
    }
};
