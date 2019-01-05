/*
https://leetcode.com/problems/intersection-of-two-linked-lists/

Runtime: 36 ms
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p=headA;
        ListNode* q=headB;
        if(headA==NULL||headB==NULL) return NULL;
        while(p!=q){
            p=p==NULL?headB:p->next;
            q=q==NULL?headA:q->next;
        }
        return p;
    }
};
