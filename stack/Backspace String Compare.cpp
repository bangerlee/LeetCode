/*
https://leetcode.com/problems/backspace-string-compare/
*/
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> ss;
        stack<char> tt;
        for(auto& c:S){
            if(ss.empty()&&c!='#') ss.push(c);
            else if(!ss.empty()&&c=='#') ss.pop();
            else if(c!='#') ss.push(c);
        }
        for(auto& c:T){
            if(tt.empty()&&c!='#') tt.push(c);
            else if(!tt.empty()&&c=='#') tt.pop();
            else if(c!='#') tt.push(c);
        }
        string stmp="",ttmp="";
        while(!ss.empty()){
            stmp+=string(1,ss.top());
            ss.pop();
        }
        while(!tt.empty()){
            ttmp+=string(1,tt.top());
            tt.pop();
        }
        return stmp==ttmp;
    }
};
