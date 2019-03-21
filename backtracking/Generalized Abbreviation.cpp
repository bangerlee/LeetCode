/*
https://leetcode.com/problems/generalized-abbreviation/

*/
class Solution {
private:
    void helper(vector<string>& res,string& word,string cur,int pos,int count){
        if(pos==word.length()){
            if(count>0) cur+=to_string(count);
            res.push_back(cur);
            return;
        }
        helper(res,word,cur,pos+1,count+1);
        helper(res,word,cur+(count>0?to_string(count):"")+word[pos],pos+1,0);
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        helper(res,word,"",0,0);
        return res;
    }
};
