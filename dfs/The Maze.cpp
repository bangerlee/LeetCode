/*
https://leetcode.com/problems/the-maze/

*/
class Solution {
private:
    bool dfs(vector<vector<int>>& maze,vector<vector<int>>& visited,int row,int col,vector<int>& des){
        int m=maze.size(),n=maze[0].size();
        if(visited[row][col]) return false;
        visited[row][col]=1;
        if(row==des[0]&&col==des[1]) return true;
        vector<int> d1({0,1,0,-1}),d2({1,0,-1,0});
        for(int i=0;i<4;i++){
            int r=row+d1[i],c=col+d2[i];
            while(r>=0&&r<m&&c>=0&&c<n&&maze[r][c]==0){
                r+=d1[i];
                c+=d2[i];
            }
            r-=d1[i];
            c-=d2[i];
            if(dfs(maze,visited,r,c,des)) return true;
        }
        return false;
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m=maze.size(),n=maze[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        return dfs(maze,visited,start[0],start[1],destination);
    }
};
