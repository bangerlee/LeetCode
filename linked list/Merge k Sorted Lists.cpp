/*
https://leetcode.com/problems/merge-k-sorted-lists/

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
    struct compare{
        bool operator()(const ListNode* l,const ListNode* r){
            return l->val>r->val;
        }  
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(ListNode* c:lists) if(c) pq.push(c);
        if(pq.empty()) return NULL;
        ListNode* res=pq.top();pq.pop();
        if(res->next) pq.push(res->next);
        ListNode* tail=res;
        while(!pq.empty()){
            tail->next=pq.top();pq.pop();
            tail=tail->next;
            if(tail->next) pq.push(tail->next);
        }
        return res;
    }
};
