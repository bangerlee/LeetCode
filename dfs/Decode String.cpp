/*
https://leetcode.com/problems/decode-string/

*/
class Solution {
private:
    string decode(string s,int& pos){
        string res="";
        int num=0;
        for(;pos<s.length();pos++){
            if(s[pos]=='['){
                string tmp=decode(s,++pos);
                for(;num>0;num--) res+=tmp;
            }
            else if(s[pos]>='0'&&s[pos]<='9')
                num=num*10+s[pos]-'0';
                else if(s[pos]==']') return res;
                else
                    res+=s[pos];
        }
        return res;
    }
public:
    string decodeString(string s) {
        int i=0;
        return decode(s,i);
    }
};
