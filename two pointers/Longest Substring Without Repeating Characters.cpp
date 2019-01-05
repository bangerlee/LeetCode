/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Runtime: 36 ms
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int i=0,res=0;
        for(int j=0;j<s.length();j++){
            if(m[s[j]]++){
                res=max(res,j-i);
                while(i<j&&s[i]!=s[j]){
                    m[s[i++]]--;
                }
                m[s[j]]--;
                i++;
            }
            else res=max(res,j-i+1);
        }
        return res;
    }
};
