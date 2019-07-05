/*
https://leetcode.com/problems/roman-to-integer/
*/
class Solution {
private:
    unordered_map<char,int> m={
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
public:
    int romanToInt(string s) {
        stack<char> st;
        int sum=0;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(((s[i]=='V'||s[i]=='X')&&st.top()=='I') || 
               ((s[i]=='L'||s[i]=='C')&&st.top()=='X') ||
               ((s[i]=='D'||s[i]=='M')&&st.top()=='C')){
                sum=sum-m[st.top()]+m[s[i]];
                st.pop();
                continue;
            }
            else st.push(s[i]);
        }
        while(!st.empty()){
            sum+=m[st.top()];
            st.pop();
        }
        return sum;
    }
};
