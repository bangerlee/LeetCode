/*
https://leetcode.com/problems/add-two-numbers-ii/

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
private:
    ListNode* reverse(ListNode* head){
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        ListNode* p=head;
        ListNode* t=p->next;
        ListNode* tt=NULL;
        while(t!=NULL){
            tt=t->next;
            t->next=p;
            p=t;
            t=tt;
        }
        head->next=NULL;
        return p;
    }
    ListNode* plus(ListNode* l1,ListNode* l2){
        ListNode* d1=l1;
        ListNode* d2=l2;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* pd1=NULL;
        int f=0;
        while(d1!=NULL&&d2!=NULL){
            int tmp=d1->val+d2->val+f;
            if(tmp>=10){
                tmp-=10;
                f=1;
            }
            else f=0;
            d1->val=tmp;
            pd1=d1;
            d1=d1->next;
            d2=d2->next;
        }
        if(d2!=NULL){
            pd1->next=d2;
            d1=d2;
        }
        while(d1!=NULL){
            d1->val+=f;
            if(d1->val>=10){
                d1->val-=10;
                f=1;
            }
            else{
                f=0;
                break;
            }
            pd1=d1;
            d1=d1->next;
        }
        if(f==1){
            ListNode* e=new ListNode(1);
            //e->val=1;
            pd1->next=e;
            e->next=NULL;
        }
        return l1;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        l1=plus(l1,l2);
        l1=reverse(l1);
        return l1;
    }
};
