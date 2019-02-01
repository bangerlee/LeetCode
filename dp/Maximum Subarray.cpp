/*
https://leetcode.com/problems/maximum-subarray/

*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=dp[i-1]<0?nums[i]:dp[i-1]+nums[i];
            res=max(dp[i],res);
        }
        return res;
    }
};
