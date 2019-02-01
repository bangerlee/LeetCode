/*
https://leetcode.com/problems/minimum-path-sum/

*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> psum(m,vector<int>(n,grid[0][0]));
        for(int i=1;i<n;i++)
            psum[0][i]=grid[0][i]+psum[0][i-1];
        for(int j=1;j<m;j++)
            psum[j][0]=grid[j][0]+psum[j-1][0];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                psum[i][j]=min(psum[i-1][j],psum[i][j-1])+grid[i][j];
            }
        }
        return psum[m-1][n-1];
    }
};
