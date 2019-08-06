/*
https://leetcode.com/problems/palindrome-linked-list/

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
    bool helper(ListNode*& head,ListNode* p){
        if(p==NULL) return true;
        bool res=helper(head,p->next);
        if(head->val!=p->val) return false;
        head=head->next;
        return res;
    }
public:
    bool isPalindrome(ListNode* head) {
        return helper(head,head);
    }
};
