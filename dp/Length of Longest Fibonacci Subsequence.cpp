/*
https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int res=0;
        unordered_map<int,int> m;
        int N=A.size();
        vector<vector<int>> dp(N,vector<int>(N));
        for(int j=0;j<N;j++){
            m[A[j]]=j;
            for(int i=0;i<j;i++){
                int k=m.find(A[j]-A[i])==m.end()?-1:m[A[j]-A[i]];
                dp[i][j]=(A[j]-A[i]<A[i]&&k>=0)?dp[k][i]+1:2;
                res=max(res,dp[i][j]);
            }
        }
        return res>2?res:0;
    }
};
