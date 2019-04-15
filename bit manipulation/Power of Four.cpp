/*
https://leetcode.com/problems/power-of-four/

*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num==INT_MIN) return false;
        return !(num&(num-1)) && (num&0x55555555);
    }
};
