/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=new ListNode(0);
        ListNode* slow=start,*fast=start;
        slow->next=head;
        for(int i=1;i<=n+1;i++) fast=fast->next;
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return start->next;
    }
};
