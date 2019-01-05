/*
https://leetcode.com/problems/merge-k-sorted-lists/

Runtime: 500 ms
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        //head=lists[0];
        int min=INT_MAX;
        int k=0;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL&&min>=lists[i]->val){
                min=lists[i]->val;
                k=i;
            }
        }
        head=lists[k];
        if(lists[k]!=NULL)
            lists[k]=lists[k]->next;
        ListNode* p=head;
        bool f=true;
        int q=0;
        while(f){
            min=INT_MAX;
            k=0;
            q=0;
            for(int i=0;i<lists.size();i++){
            if(lists[i]==NULL){
                q++;
                continue;
            }
                if(lists[i]->val<=min){
                    min=lists[i]->val;
                    k=i;
                }
            }
            if(q==lists.size()) break;
            p->next=lists[k];
            lists[k]=lists[k]->next;
            p=p->next;
            //if(i==lists.size()) break;
        }
        return head;
    }
};
