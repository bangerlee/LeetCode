/*
https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy=new ListNode(0), *pre=dummy, *cur;
        dummy->next=head;
        for(int i=0;i<m-1;i++) pre=pre->next;
        cur=pre->next;
        for(int i=0;i<n-m;i++){
            ListNode* tmp=pre->next;
            pre->next=cur->next;
            cur->next=cur->next->next;
            pre->next->next=tmp;
        }
        return dummy->next;
    }
};
