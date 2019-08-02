/*
https://leetcode.com/problems/longest-word-in-dictionary/

*/
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        unordered_set<string> s;
        string res="";
        for(string w:words){
            if(w.length()==1 || s.count(w.substr(0,w.length()-1))){
                res=res.length()<w.length()?w:res;
                s.insert(w);
            }
        }
        return res;
    }
};
