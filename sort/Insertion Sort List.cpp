/*
https://leetcode.com/problems/insertion-sort-list/

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
        ListNode* dummy=new ListNode(0);
        ListNode* cur=head;
        ListNode* prev=dummy;
        ListNode* next=NULL;
        while(cur){
            next=cur->next;
            if(!prev||!prev->next||prev->next->val>=cur->val) prev=dummy;
            while(prev->next&&prev->next->val<cur->val) prev=prev->next;
            cur->next=prev->next;
            prev->next=cur;
            cur=next;
        }
        return dummy->next;
    }
};
