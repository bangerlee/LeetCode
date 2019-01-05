/*
https://leetcode.com/problems/swap-nodes-in-pairs/

Runtime: 4 ms
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        ListNode* nhead=head->next;
        ListNode* e=head;
        ListNode* b=nhead;
        do{
            ListNode* tmp=b->next;
            b->next=e;
            e->next=tmp;
            if(tmp==NULL) break;
            b=tmp->next;
            if(b!=NULL) e->next=b;
            e=tmp;
        }while(b!=NULL);
        return nhead;
    }
};
