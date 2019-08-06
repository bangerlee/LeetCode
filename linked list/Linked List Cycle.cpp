/*
https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* p=head;
        ListNode* pp=head;
        while(pp->next!=NULL&&pp->next->next!=NULL){
            p=p->next;
            pp=pp->next->next;
            if(pp==p) return true;
        }
        return false;
    }
};
