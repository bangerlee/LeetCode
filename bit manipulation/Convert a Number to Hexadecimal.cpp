/*
https://leetcode.com/problems/convert-a-number-to-hexadecimal/

*/
class Solution {
public:
    string toHex(int num) {
        string s="0123456789abcdef";
        string res="";
        if(num==0) return "0";
        int count=0;
        while(num&&count++<8){
            res=s[num&0xf]+res;
            num>>=4;
        }
        return res;
    }
};
