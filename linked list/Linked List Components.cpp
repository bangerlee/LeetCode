/*
https://leetcode.com/problems/linked-list-components/

Runtime: 352 ms
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
        int res=0;
        ListNode* p=head;
        while(p!=NULL){
            if(find(G.begin(),G.end(),p->val)!=G.end()){
                while(p!=NULL&&find(G.begin(),G.end(),p->val)!=G.end()){
                    p=p->next;
                }
                res+=1;
            }
            if(p!=NULL)
                p=p->next;
        }
        return res;
    }
};
