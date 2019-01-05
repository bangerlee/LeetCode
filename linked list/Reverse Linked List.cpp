/*
https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* idx=head;
        ListNode* a=idx->next;
        ListNode* b=NULL;
        while(a!=NULL){
            idx->next=b;
            b=idx;
            idx=a;
            a=a->next;
        }
        idx->next=b;
        return idx;
    }
};
