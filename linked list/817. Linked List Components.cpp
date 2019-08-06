/*
https://leetcode.com/problems/linked-list-components/

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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> setG(G.begin(),G.end());
        int res=0;
        while(head!=NULL){
            if(setG.count(head->val)&&(head->next==NULL||!setG.count(head->next->val)))
                res++;
            head=head->next;
        }
        return res;
    }
};
