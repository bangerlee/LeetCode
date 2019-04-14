/*
https://leetcode.com/problems/hamming-distance/

*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int k=x^y,res=0;
        while(k!=0){
            k&=k-1;
            ++res;
        }
        return res;
    }
};
