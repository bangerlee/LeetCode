/*
https://leetcode.com/problems/generate-parentheses/

*/
class Solution {
private:
    void bkt(vector<string>& v,string s,int open,int close,int max){
        if(s.length()==max*2) {
            v.push_back(s);
            return;
        }
        if(open<max) bkt(v,s+"(",open+1,close,max);
        if(close<open) bkt(v,s+")",open,close+1,max);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        bkt(v,"",0,0,n);
        return v;
    }
};
