/*
https://leetcode.com/problems/insertion-sort-list/

Runtime: 44 ms
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
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* p=head->next;
        head->next=NULL;
        while(p!=NULL){
            ListNode* phead=head;
            ListNode* pr=NULL;
            while(phead!=NULL && p->val>=phead->val)
            {
                pr=phead;
                phead=phead->next;
            }
            if(phead==head){
                phead=p;
                p=p->next;
                phead->next=head;
                head=phead;
            }
            else if(phead==NULL){
                pr->next=p;
                p=p->next;
                pr->next->next=NULL;
            }
            else{
                pr->next=p;
                p=p->next;
                pr->next->next=phead;
            }
        }
        return head;
    }
};
