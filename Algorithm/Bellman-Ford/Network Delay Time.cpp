/*
https://leetcode.com/problems/network-delay-time/

*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(times.size()==0) return -1;
        vector<int> dp(N+1,INT_MAX);
        dp[K]=0;
        for(int i=0;i<N;i++){
            for(auto edge:times){
                int src=edge[0],dst=edge[1],time=edge[2];
                if(dp[src]!=INT_MAX&&time+dp[src]<dp[dst]) dp[dst]=time+dp[src];
            }
        }
        int res=0;
        for(int i=1;i<=N;i++) if(dp[i]>res) res=dp[i];
        return res==INT_MAX?-1:res;
    }
};
