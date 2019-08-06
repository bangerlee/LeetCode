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
        if(head==NULL) return NULL;
        ListNode* cur=head;
        ListNode* p=cur->next;
        ListNode* pre=NULL;
        while(p!=NULL){
            cur->next=pre;
            pre=cur;
            cur=p;
            p=p->next;
        }
        cur->next=pre;
        return cur;
    }
};
