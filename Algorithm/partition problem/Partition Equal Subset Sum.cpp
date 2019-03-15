/*
https://leetcode.com/problems/partition-equal-subset-sum/

*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num:nums) sum+=num;
        if(sum%2!=0) return false;
        sum/=2;
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(sum+1,false));
        dp[0][0]=true;
        for(int i=1;i<nums.size()+1;i++) dp[i][0]=true;
        for(int j=1;j<sum+1;j++) dp[0][j]=false;
        for(int i=1;i<nums.size()+1;i++){
            for(int j=1;j<sum+1;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i-1]) dp[i][j]=dp[i][j]||dp[i-1][j-nums[i-1]];
            }
        }
        return dp[nums.size()][sum];
    }
};
