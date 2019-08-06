/*
https://leetcode.com/problems/add-two-numbers-ii/

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
        stack<int> sl1;
        stack<int> sl2;
        while(l1!=NULL) sl1.push(l1->val),l1=l1->next;
        while(l2!=NULL) sl2.push(l2->val),l2=l2->next;
        int c=0;
        ListNode* pre=new ListNode(0);
        while(!sl1.empty()||!sl2.empty()||c){
            int a=0,b=0;
            if(!sl1.empty()) a=sl1.top(),sl1.pop();
            if(!sl2.empty()) b=sl2.top(),sl2.pop();
            int sum=a+b+c;
            ListNode* node=new ListNode(sum%10);
            c=sum/10;
            ListNode* next=pre->next;
            pre->next=node;
            pre->next->next=next;
        }
        return pre->next;
    }
};
