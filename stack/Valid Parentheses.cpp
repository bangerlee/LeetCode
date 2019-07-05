/*
https://leetcode.com/problems/valid-parentheses/
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char x:s){
            if(st.empty()) st.push(x);
            else if(st.top()=='('&&x==')') st.pop();
            else if(st.top()=='['&&x==']') st.pop();
            else if(st.top()=='{'&&x=='}') st.pop();
            else st.push(x);
        }
        return st.empty()?true:false;
    }
};
