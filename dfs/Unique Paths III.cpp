/*
https://leetcode.com/problems/unique-paths-iii/

*/
class Solution {
private:
    void backtrack(vector<vector<int>>& grid,int& res,int i,int j,int m,int n,int& num0,int& cur){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==-1||grid[i][j]==3) return;
        if(cur==num0&&grid[i][j]==2){
            ++res;
            return;
        }
        else if(grid[i][j]==2&&cur!=num0) return;
        else if(grid[i][j]==1&&cur!=0) return;
        if(grid[i][j]==0){
            grid[i][j]=3;
            ++cur;
        }
        backtrack(grid,res,i-1,j,m,n,num0,cur);
        backtrack(grid,res,i+1,j,m,n,num0,cur);
        backtrack(grid,res,i,j-1,m,n,num0,cur);
        backtrack(grid,res,i,j+1,m,n,num0,cur);
        if(grid[i][j]==3){
            grid[i][j]=0;
            --cur;
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int res=0,m=grid.size(),n=grid[0].size();
        int num0=0,k=0,q=0,cur=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) ++num0;
                else if(grid[i][j]==1) k=i,q=j;
            }
        }
        backtrack(grid,res,k,q,m,n,num0,cur);
        return res;
    }
};
