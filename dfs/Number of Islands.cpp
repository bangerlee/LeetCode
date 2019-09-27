/*
https://leetcode.com/problems/number-of-islands/

*/
class Solution {
private:
    void helper(vector<vector<char>>& grid,int i,int j,int m,int n){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!='1') return;
        grid[i][j]='0';
        helper(grid,i-1,j,m,n);
        helper(grid,i+1,j,m,n);
        helper(grid,i,j-1,m,n);
        helper(grid,i,j+1,m,n);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int m=grid.size(),n=grid[0].size(),res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]=='1'){
                    helper(grid,i,j,m,n);
                    res++;
                }
        return res;
    }
};
