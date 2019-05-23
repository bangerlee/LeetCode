/*
https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> neet(128,0);
        vector<int> res;
        for(char c:p) neet[c]++;
        int begin=0,end=0,cnt=p.length();
        while(end<s.length()){
            if(neet[s[end++]]--) cnt--;
            if(!cnt) res.push_back(begin);
            if(end-begin>=p.length()&&neet[s[begin++]]++>=0) cnt++;
        }
        return res;
    }
};
