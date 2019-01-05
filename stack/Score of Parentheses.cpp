/*
https://leetcode.com/problems/score-of-parentheses/

Runtime: 4 ms
*/
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        st.push(0);
        for(char c : S){
            if(c=='(') st.push(0);
            else{
                int val=st.top();
                st.pop();
                val=st.top()+max(val*2,1);
                st.pop();
                st.push(val);
            }
        }
        return st.top();
    }
};
