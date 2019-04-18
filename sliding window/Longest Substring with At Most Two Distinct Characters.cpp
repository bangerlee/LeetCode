/*
https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

*/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int cnt=0,begin=0,end=0,res=0;
        vector<int> v(128,0);
        while(end<s.length()){
            if(v[s[end++]]++==0) cnt++;
            while(cnt>2) if(v[s[begin++]]--==1) cnt--;
            res=max(res,end-begin);
        }
        return res;
    }
};
