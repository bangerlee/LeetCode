/*
https://leetcode.com/problems/shortest-bridge/

*/
class Solution {
private:
    vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& A,vector<vector<bool>>& visited,queue<vector<int>>& q,int i,int j){
        if(i<0||i>=A.size()||j<0||j>=A[0].size()||visited[i][j]||A[i][j]==0) return;
        visited[i][j]=true;
        q.push({i,j});
        for(auto dir:dirs)
            dfs(A,visited,q,i+dir[0],j+dir[1]);
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m=A.size(),n=A[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<vector<int>> q;
        bool found=false;
        for(int i=0;i<m;i++){
            if(found) break;
            for(int j=0;j<n;j++){
                if(A[i][j]==1){
                    dfs(A,visited,q,i,j);
                    found=true;
                    break;
                }
            }
        }
        
        int res=0;
        while(!q.empty()){
            int size=q.size();
            while(size-- > 0){
                vector<int> cur=q.front();q.pop();
                for(auto dir:dirs){
                    int x=cur[0]+dir[0],y=cur[1]+dir[1];
                    if(x<0||x>=m||y<0||y>=n||visited[x][y]) continue;
                    if(A[x][y]==1) return res;
                    q.push({x,y});
                    visited[x][y]=true;
                }
            }
            res++;
        }
        return -1;
    }
};
