/*
https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/

*/
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int low=INT_MIN;
        for(int x:preorder){
            if(x<low) return false;
            while(!st.empty()&&x>st.top()){
                low=st.top();
                st.pop();
            }
            st.push(x);
        }
        return true;
    }
};
