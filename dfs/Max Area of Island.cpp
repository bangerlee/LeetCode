/*
https://leetcode.com/problems/max-area-of-island/

*/
class Solution {
private:
    int helper(vector<vector<int>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()) return 0;
        if(grid[i][j]==0) return 0;
        grid[i][j]=0;
        return 1+helper(grid,i-1,j)+helper(grid,i+1,j)+helper(grid,i,j-1)+helper(grid,i,j+1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    res=max(res,helper(grid,i,j));
            }
        }
        return res;
    }
};
