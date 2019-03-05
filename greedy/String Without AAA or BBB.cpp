/*
https://leetcode.com/problems/string-without-aaa-or-bbb/

*/
class Solution {
private:
    void helper(int A,int B,char a,char b,string& res){
        if(B>A) return helper(B,A,b,a,res);
        while(A-->0){
            res+=a;
            if(A>B) res+=a,A--;
            if(B-->0) res+=b;
        }
    }
public:
    string strWithout3a3b(int A, int B) {
        string res="";
        helper(A,B,'a','b',res);
        return res;
    }
};
