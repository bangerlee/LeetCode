/*
https://leetcode.com/problems/minimum-window-substring/
*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(char c : t) m[c]++;
        int begin=0,end=0,minlen=INT_MAX,count=t.size(),start=0;
        while(end<s.length()){
            if(m[s[end]]-->0) count--;
            end++;
            while(count==0){
                if(minlen>end-begin){
                    minlen=end-begin;
                    start=begin;
                }
                if(++m[s[begin]]>0) count++;
                begin++;
            }
        }
        if(minlen!=INT_MAX)
            return s.substr(start,minlen);
        return "";
    }
};
