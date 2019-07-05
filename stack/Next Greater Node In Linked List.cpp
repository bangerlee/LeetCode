/*
https://leetcode.com/problems/next-greater-node-in-linked-list/
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<int> st;
        for(auto p=head;p!=NULL;p=p->next) res.push_back(p->val);
        for(int i=res.size()-1;i>=0;i--){
            int val=res[i];
            while(!st.empty() && st.top()<=res[i]) st.pop();
            res[i]=st.empty()?0:st.top();
            st.push(val);
        }
        return res;
    }
};
