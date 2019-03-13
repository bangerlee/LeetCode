/*
https://leetcode.com/problems/the-maze/

*/
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int,int>> v;
        int m=maze.size(),n=maze[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        if(start[0]==destination[0]&&start[1]==destination[1]) return true;
        vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
        visited[start[0]][start[1]]=true;
        v.push({start[0],start[1]});
        while(!v.empty()){
            pair<int,int> point=v.front();
            v.pop();
            int x=point.first,y=point.second;
            for(int i=0;i<4;i++){
                int xx=x,yy=y;
                while(xx>=0&&yy>=0&&xx<m&&yy<n&&maze[xx][yy]==0){
                    xx+=dir[i][0];
                    yy+=dir[i][1];
                }
                xx-=dir[i][0];
                yy-=dir[i][1];
                if(visited[xx][yy]) continue;
                visited[xx][yy]=true;
                if(xx==destination[0]&&yy==destination[1]) return true;
                v.push({xx,yy});
            }
        }
        return false;
    }
};
