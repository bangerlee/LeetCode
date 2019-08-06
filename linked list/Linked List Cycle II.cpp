/*
https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return NULL;
        ListNode* firstp=head;
        ListNode* secondp=head;
        bool isCycle=false;
        while(secondp!=NULL&&secondp->next!=NULL){
            firstp=firstp->next;
            secondp=secondp->next->next;
            if(firstp==secondp){
                isCycle=true;
                break;
            }
        }
        if(!isCycle) return NULL;
        firstp=head;
        while(firstp!=secondp){
            firstp=firstp->next;
            secondp=secondp->next;
        }
        return firstp;
    }
};
