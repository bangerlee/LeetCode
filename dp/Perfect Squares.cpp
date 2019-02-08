/*
https://leetcode.com/problems/perfect-squares/

*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int m=INT_MAX;
            for(int j=1;i-j*j>=0;j++)
                m=min(m,dp[i-j*j]+1);
            dp[i]=m;
        }
        return dp[n];
    }
};
