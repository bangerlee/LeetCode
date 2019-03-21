/*
https://leetcode.com/problems/4-keys-keyboard/

*/
class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N+1);
        for(int i=1;i<=N;i++){
            dp[i]=i;
            for(int j=3;j<i;j++) dp[i]=max(dp[i],dp[i-j]*(j-1));
        }
        return dp[N];
    }
};
