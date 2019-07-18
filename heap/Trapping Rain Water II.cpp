class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        typedef pair<int,int> cell;
        priority_queue<cell, vector<cell>, greater<cell>> q;
        int m=heightMap.size();
        if(m==0) return 0;
        int n=heightMap[0].size();
        vector<int> visited(m*n, false);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(!visited[i*n+j]) q.push(cell(heightMap[i][j], i*n+j));
                    visited[i*n+j]=true;
                }
            }
        }
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        int res=0;
        while(!q.empty()){
            cell c=q.top(); q.pop();
            int i=c.second/n, j=c.second%n;
            for(int r=0;r<4;r++){
                int x=i+dir[r][0], y=j+dir[r][1];
                if(x<0 || x>=m || y<0 || y>=n || visited[x*n+y]) continue;
                res+=max(0, c.first-heightMap[x][y]);
                q.push(cell(max(c.first, heightMap[x][y]), x*n+y));
                visited[x*n+y]=true;
            }
        }
        return res;
    }
};
