/*
https://leetcode.com/problems/coloring-a-border/

*/
class Solution {
private:
     vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
     void fill(vector<vector<int>>& res,int sr,int sc,int color,vector<vector<bool>>& flag){
         if(sr<0||sc<0||sr>=res.size()||sc>=res[0].size()) return;
         if(flag[sr][sc]) return;
         if(res[sr][sc]!=color) return;
         flag[sr][sc]=true;
         if(sr==0||sr==res.size()-1||sc==0||sc==res[0].size()-1)
            res[sr][sc]=-1;
         for(auto d:dir){
             int x=sr+d[0],y=sc+d[1];
             if(x>=0&&x<res.size()&&y>=0&&y<res[0].size()&&res[x][y]==-1) continue;
             if(x>=0&&x<res.size()&&y>=0&&y<res[0].size()&&res[x][y]!=color){
                 res[sr][sc]=-1;
             }
         }
         fill(res,sr-1,sc,color,flag);
         fill(res,sr,sc-1,color,flag);
         fill(res,sr+1,sc,color,flag);
         fill(res,sr,sc+1,color,flag);
     }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        if(grid[r0][c0]==color) return grid;
        vector<vector<bool>> flag(grid.size(),vector<bool>(grid[0].size(),false));
        fill(grid,r0,c0,grid[r0][c0],flag);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==-1) grid[i][j]=color;
        }
        return grid;        
    }
};
