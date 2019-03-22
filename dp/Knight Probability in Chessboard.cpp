/*
https://leetcode.com/problems/knight-probability-in-chessboard/

*/
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<int>> dir={{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
        int len=N;
        vector<vector<double>> dp(len,vector<double>(len,1.0));
        for(int p=0;p<K;p++){
            vector<vector<double>> dp1(len,vector<double>(len));
            for(int i=0;i<len;i++){
                for(int j=0;j<len;j++){
                    for(auto move:dir){
                        int row=i+move[0];
                        int col=j+move[1];
                        if(row<0||row>=len||col<0||col>=len) continue;
                        dp1[i][j]+=dp[row][col];
                    }
                }
            }
            dp=dp1;
        }
        return dp[r][c]/pow(8,K);
    }
};
