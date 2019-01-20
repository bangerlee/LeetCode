/*
https://leetcode.com/problems/longest-word-in-dictionary/

*/
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        unordered_set<string> s;
        string res="";
        for(string x:words){
            if(x.length()==1||s.count(x.substr(0,x.length()-1))){
                res=res.length()<x.length()?x:res;
                s.insert(x);
            }
        }
        return res;
    }
};
