/*
https://leetcode.com/problems/bitwise-and-of-numbers-range/

*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res=0;
        while(n!=m){
            res++;
            n>>=1;
            m>>=1;
        }
        return m<<res;
    }
};
