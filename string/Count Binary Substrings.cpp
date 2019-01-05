/*
https://leetcode.com/problems/count-binary-substrings/

Runtime: 28 ms
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int idx=1,res=0,prev=0,curr=1;
        if(s.length()<2) return 0;
        for(;idx<s.length();idx++){
            if(s[idx]==s[idx-1]) curr++;
            else{
                prev=curr;
                curr=1;
            }
            if(prev>=curr) res++;
        }
        return res;
    }
};
