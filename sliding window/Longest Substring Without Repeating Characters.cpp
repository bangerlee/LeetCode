/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/

*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128,0);
        int begin=0,end=0,res=0,cnt=0;
        while(end<s.length()){
            if(v[s[end++]]++>0) cnt++;
            while(cnt>0) if(v[s[begin++]]-->1) cnt--;
            res=max(res,end-begin);
        }
        return res;
    }
};
