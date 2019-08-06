/*
https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p=new ListNode(0);
        ListNode* head=p;
        int carry=0;
        while(l1!=NULL||l2!=NULL||carry!=0){
            if(l1!=NULL) carry+=l1->val,l1=l1->next;
            if(l2!=NULL) carry+=l2->val,l2=l2->next;
            ListNode* node=new ListNode(carry%10);
            carry/=10;
            p->next=node;
            p=node;
        }
        return head->next;
    }
};
