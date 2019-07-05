/*
https://leetcode.com/problems/tag-validator/
*/
class Solution {
public:
    bool isValid(string code) {
        stack<string> st;
        for(int i=0;i<code.length();i++){
            if(i>0 && st.empty()) return false;
            if(code.substr(i,9)=="<![CDATA["){
                int j=i+9;
                i=code.find("]]>",j);
                if(i<0) return false;
                i+=2;
            }
            else if(code.substr(i,2)=="</"){
                int j=i+2;
                i=code.find('>',j);
                string s=code.substr(j,i-j);
                if(st.empty() || s!=st.top()) return false;
                st.pop();
            }
            else if(code.substr(i,1)=="<"){
                int j=i+1;
                i=code.find('>',j);
                if(i<0 || i==j || i-j>9) return false;
                for(int k=j;k<i;k++){
                    if(!isupper(code[k])) return false;
                }
                string s=code.substr(j,i-j);
                st.push(s);
            }
        }
        return st.empty();
    }
};
