/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
        ListNode* idx=head;
        if(idx==NULL)
            return head;
        while(idx->next!=NULL){
            if(idx->val==idx->next->val)
                idx->next=idx->next->next;
            else
                idx=idx->next;
        }
        return head;
    }
};
