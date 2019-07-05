/*
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for(auto c:S){
            if(st.empty()) st.push(c);
            else if(st.top()==c) st.pop();
            else st.push(c);
        }
        string res="";
        while(!st.empty()){
            res+=string(1,st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
