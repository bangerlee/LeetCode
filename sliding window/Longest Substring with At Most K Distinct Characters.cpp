/*
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> v(128,0);
        int res=0,cnt=0,begin=0,end=0;
        while(end<s.length()){
            if(v[s[end++]]++==0) cnt++;
            while(cnt>k) if(v[s[begin++]]--==1) cnt--;
            res=max(res,end-begin);
        }
        return res;
    }
};
