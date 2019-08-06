/*
https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        for(ListNode* i=head;i!=NULL;n++,i=i->next);
        ListNode* dmy=new ListNode(0);
        dmy->next=head;
        for(ListNode* prev=dmy,* tail=head;n>=k;n-=k){
            for(int i=1;i<k;i++){
                ListNode* next=tail->next->next;
                tail->next->next=prev->next;
                prev->next=tail->next;
                tail->next=next;
            }
            prev=tail;
            tail=tail->next;
        }
        return dmy->next;
    }
};
