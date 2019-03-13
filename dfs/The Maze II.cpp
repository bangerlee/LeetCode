/*
https://leetcode.com/problems/the-maze-ii/

*/
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int res=INT_MAX,tmp=0;
        int m=maze.size(),n=maze[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>> dist(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        if(start[0]==destination[0]&&start[1]==destination[1]) return 0;
        q.push({start[0],start[1]});
        dist[start[0]][start[1]]=0;
        while(!q.empty()){
            pair<int,int> point=q.front();
            q.pop();
            int x=point.first,y=point.second;
            int distence=dist[x][y];
            for(int i=0;i<4;i++){
                int xx=x,yy=y,steps=0;
                while(xx>=0&&xx<m&&yy>=0&&yy<n&&maze[xx][yy]==0){
                    xx+=dir[i][0];
                    yy+=dir[i][1];
                    steps++;
                }
                xx-=dir[i][0];
                yy-=dir[i][1];
                steps--;
                if(visited[xx][yy]==false){
                    dist[xx][yy]=distence+steps;
                    visited[xx][yy]=true;
                    q.push(pair{xx,yy});
                }
                else{
                    if(dist[xx][yy]>distence+steps) {
                        dist[xx][yy]=distence+steps;
                        q.push(pair{xx,yy});
                    }
                }
            }
        }
        return dist[destination[0]][destination[1]];
    }
};
