/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* dummp=new ListNode(0);
        dummp->next=head;
        ListNode* pre=dummp,*cur=head;
        while(cur!=NULL){
            while(cur->next!=NULL&&cur->val==cur->next->val) cur=cur->next;
            if(pre->next==cur) pre=pre->next;
            else pre->next=cur->next;
            cur=cur->next;
        }
        return dummp->next;
    }
};
