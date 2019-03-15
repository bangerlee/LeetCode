/*
https://leetcode.com/problems/ternary-expression-parser/

*/
class Solution {
public:
    string parseTernary(string expression) {
        stack<char> st;
        if(expression.length()==0) return "";
        for(int i=expression.length()-1;i>=0;i--){
            if(!st.empty()&&st.top()=='?'){
                st.pop();
                char a=st.top();st.pop();
                st.pop();//:
                char b=st.top();st.pop();
                if(expression[i]=='T') st.push(a);
                else st.push(b);
            }
            else st.push(expression[i]);
        }
        return string(1,st.top());
    }
};
