/*
https://leetcode.com/problems/coin-change/

*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int x=1;x<=amount;x++){
            for(int i:coins){
                if(x>=i)
                    dp[x]=min(dp[x],dp[x-i]+1);
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};
