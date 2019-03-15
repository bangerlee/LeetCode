/*
https://leetcode.com/problems/target-sum/

*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        for(auto num:nums) sum+=num;
        if(sum<S||(sum+S)%2!=0) return 0;
        sum=(sum+S)/2;
        vector<int> dp(sum+1,0);
        dp[0]=1;
        for(auto num:nums)
            for(int j=sum;j>=num;j--)
                dp[j]+=dp[j-num];
        return dp[sum];
    }
};
