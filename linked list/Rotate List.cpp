/*
https://leetcode.com/problems/rotate-list/


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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int len=1;
        ListNode* newHead,*tail;
        newHead=tail=head;
        while(tail->next){
            tail=tail->next;
            len++;
        }
        tail->next=head;
        if(k%=len)
            for(int i=0;i<len-k;i++) tail=tail->next;
        newHead=tail->next;
        tail->next=NULL;
        return newHead;
    }
};
