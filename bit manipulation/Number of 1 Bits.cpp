/*
https://leetcode.com/problems/number-of-1-bits/

*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n!=0){
            n=n&(n-1);
            ++res;
        }
        return res;
    }
};
