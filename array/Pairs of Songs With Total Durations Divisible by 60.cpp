/*
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

*/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(60,0);
        int res=0;
        for(auto x:time){
            res+=v[(60-x%60)%60];
            v[x%60]++;
        }
        return res;
    }
};
