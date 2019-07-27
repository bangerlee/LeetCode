/*
https://leetcode.com/problems/shortest-path-in-binary-matrix/

*/
class Solution {
private:
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,-1},{-1,1},{1,-1}};
    struct queueNode{
        int x;
        int y;
        int dist;
    };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0||grid[n-1][n-1]!=0) return -1;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        visited[n-1][n-1]=true;
        queue<queueNode> q;
        queueNode s={n-1,n-1,1};
        q.push(s);
        while(!q.empty()){
            queueNode curr=q.front();q.pop();
            int x=curr.x,y=curr.y;
            if(x==0&&y==0) return curr.dist;
            for(int i=0;i<dir.size();i++){
                int row=x+dir[i][0],col=y+dir[i][1];
                if(row>=n||col>=n||row<0||col<0||grid[row][col]==1||visited[row][col]) continue;
                visited[row][col]=true;
                queueNode adjcell={row,col,curr.dist+1};
                q.push(adjcell);
            }
        }
        return -1;
    }
};
