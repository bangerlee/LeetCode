/*
https://leetcode.com/problems/swap-nodes-in-pairs/

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
        if(head==NULL || head->next==NULL) return head;
        ListNode* p=head->next;
        head->next=swapPairs(head->next->next);
        p->next=head;
        return p;
    }
};
