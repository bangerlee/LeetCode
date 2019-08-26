/*
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        unordered_map<int,ListNode*> m;
        m[0]=dummy;
        int sum=0;
        while(head!=NULL){
            sum+=head->val;
            if(m.count(sum)){
                ListNode* prev=m[sum];
                ListNode* start=prev;
                int tmp=sum;
                while(prev!=head){
                    prev=prev->next;
                    tmp+=prev->val;
                    if(prev!=head) m.erase(tmp);
                }
                start->next=head->next;
            }
            else m[sum]=head;
            head=head->next;
        }
        return dummy->next;
    }
};
