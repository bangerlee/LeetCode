/*
https://leetcode.com/problems/walls-and-gates/

*/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<vector<int>> q;
        vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        int m=rooms.size();
        if(m==0) return;
        int n=rooms[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(rooms[i][j]==0) q.push({i,j});
        }
        while(!q.empty()){
            vector<int> cur=q.front();q.pop();
            for(int i=0;i<dirs.size();i++){
                int x=cur[0]+dirs[i][0], y=cur[1]+dirs[i][1];
                if(x<0||x>=m||y<0||y>=n||rooms[x][y]!=INT_MAX) continue;
                rooms[x][y]=rooms[cur[0]][cur[1]]+1;
                q.push({x,y});
            }
        }
    }
};
