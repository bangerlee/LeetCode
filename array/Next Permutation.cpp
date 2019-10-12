/*
https://leetcode.com/problems/next-permutation/

*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),k=n-2;
        for(;k>=0;k--)
            if(nums[k+1]>nums[k]) break;
        if(k==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int l=n-1;
        for(;l>k;l--){
            if(nums[l]>nums[k]) break;
        }
        swap(nums[l],nums[k]);
        reverse(nums.begin()+k+1,nums.end());
    }
};
