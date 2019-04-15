/*
https://leetcode.com/problems/total-hamming-distance/

*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int bitc=0,res=0;
        uint32_t mask=1;
        for(int i=0;i<32;i++){
            bitc=0;
            for(int j=0;j<nums.size();j++)
                if(nums[j]&mask) bitc++;
            mask<<=1;
            res+=bitc*(nums.size()-bitc);
        }
        return res;
    }
};
