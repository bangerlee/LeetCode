/*
https://leetcode.com/problems/number-of-islands/

*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=m?grid[0].size():0, res=0;
        vector<vector<int>> dirs={{1,0},{-1,0},{0,-1},{0,1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    res++;
                    grid[i][j]='0';
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int,int> cell=q.front();q.pop();
                        for(int k=0;k<dirs.size();k++){
                            int x=cell.first+dirs[k][0], y=cell.second+dirs[k][1];
                            if(x<0||y<0||x>=m||y>=n||grid[x][y]!='1') continue;
                            grid[x][y]='0';
                            q.push({x,y});
                        }
                    }
                }
            }
        }
        return res;
    }
};
