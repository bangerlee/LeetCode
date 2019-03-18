/*
https://leetcode.com/problems/plus-one-linked-list/

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
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* node=head;
        ListNode* lastNotNine=dummy;
        while(node!=NULL){
            if(node->val!=9) lastNotNine=node;
            node=node->next;
        }
        lastNotNine->val++;
        node=lastNotNine->next;
        while(node!=NULL) node->val=0,node=node->next;
        return dummy->val==1?dummy:head;
    }
};
