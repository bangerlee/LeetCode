/*
https://leetcode.com/problems/rotting-oranges/

*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int num=0,res=-1;
        queue<vector<int>> q;
        vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0) num++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        while(!q.empty()){
            int size=q.size();
            res++;
            for(int i=0;i<size;i++){
                vector<int> cur=q.front();q.pop();
                num--;
                for(int j=0;j<dirs.size();j++){
                    int x=cur[0]+dirs[j][0], y=cur[1]+dirs[j][1];
                    if(x>=grid.size() || x<0 || y>=grid[0].size() || y<0 ||grid[x][y]!=1) continue;
                    grid[x][y]=2;
                    q.push({x,y});
                }
            }
        }
        return num==0?max(res,0):-1;
    }
};
