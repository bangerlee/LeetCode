/*
https://leetcode.com/problems/zigzag-conversion/

*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;
        vector<string> v(numRows,"");
        for(int i=0,step=1,row=0;i<s.length();i++){
            v[row]+=s[i];
            if(row==0) step=1;
            else if(row==numRows-1) step=-1;
            row+=step;
        }
        string res="";
        for(auto x:v) res+=x;
        return res;
    }
};
