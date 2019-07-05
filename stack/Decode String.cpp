/*
https://leetcode.com/problems/decode-string/
*/
class Solution {
public:
    string decodeString(string s) {
        string res="";
        stack<int> cntSt;
        stack<string> resSt;
        int idx=0;
        while(idx < s.length()){
            if(isdigit(s[idx])){
                int count=0;
                while(isdigit(s[idx])){
                    count=10*count+(s[idx]-'0');
                    idx++;
                }
                cntSt.push(count);
            }
            else if(s[idx]=='['){
                resSt.push(res);
                res="";
                idx++;
            }
            else if(s[idx]==']'){
                string tmp=resSt.top();resSt.pop();
                int repeatTime=cntSt.top();cntSt.pop();
                for(int i=0;i<repeatTime;i++) tmp+=res;
                res=tmp;
                idx++;
            }
            else res+=string(1,s[idx++]);
        }
        return res;
    }
};
