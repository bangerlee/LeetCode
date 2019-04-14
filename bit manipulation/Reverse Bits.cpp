/*
https://leetcode.com/problems/reverse-bits/

*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        int mask=1;
        for(int i=0;i<31;i++){
            res|=(mask&n);
            res=res<<1;
            n=n>>1;
        }
        return res|=(mask&n);
    }
};
