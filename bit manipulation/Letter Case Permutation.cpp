/*
https://leetcode.com/problems/letter-case-permutation/

*/
class Solution {
private:
    void backtrack(vector<string>& res,string& s,int start){
        res.push_back(s);
        for(int i=start;i<s.length();i++){
            if(isalpha(s[i])){
                s[i]^=32;
                backtrack(res,s,i+1);
                s[i]^=32;
            }
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(res,S,0);
        return res;
    }
};
