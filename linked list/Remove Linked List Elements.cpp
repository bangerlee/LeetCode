/*
https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* cur=dummy;
        while(cur->next!=NULL){
            if(cur->next->val==val) cur->next=cur->next->next;
            else cur=cur->next;
        }
        return dummy->next;
    }
};
