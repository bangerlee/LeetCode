/*
https://leetcode.com/problems/sort-list/

Runtime: 32 ms
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
    ListNode* mergesort(ListNode* phead){
        if(phead==NULL||phead->next==NULL) return phead;
        ListNode* fast=phead;
        ListNode* slow=phead;
        fast=fast->next;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=slow->next;
        slow->next=NULL;
        slow=mergesort(phead);
        fast=mergesort(fast);
        return merge(slow,fast);
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* rhead;
        if(head1->val>head2->val){
            rhead=head2;
            head2=head2->next;
        }
        else{
            rhead=head1;
            head1=head1->next;
        }
        ListNode* p=rhead;
        while(head1!=NULL&&head2!=NULL){
            if(head1->val>head2->val){
                p->next=head2;
                p=p->next;
                head2=head2->next;
            }
            else{
                p->next=head1;
                p=p->next;
                head1=head1->next;
            }
        }
        if(head1!=NULL)
            p->next=head1;
        else if(head2!=NULL)
            p->next=head2;
        else
            p->next=NULL;
        return rhead;
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};
