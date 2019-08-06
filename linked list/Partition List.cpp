/*
https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h=head,*t=head;
        while(head!=NULL){
            ListNode* p=head->next;
            if(head->val<x){
                head->next=h;
                h=head;
            }
            else{
                t->next=head;
                t=head;
            }
            head=p;
        }
        t->next=NULL;
        return h;
    }
};
