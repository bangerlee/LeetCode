/*
https://leetcode.com/problems/find-all-anagrams-in-a-string/

*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> m;
        int begin=0,end=0,cnt=p.length();
        for(auto& c:p) m[c]++;
        vector<int> res;
        while(end<s.length()){
            if(m[s[end++]]-->0) cnt--;
            if(cnt==0) res.push_back(begin);
            if(end-begin>=p.length()&&++m[s[begin++]]>0) cnt++;
        }
        return res;
    }
};
