/*
https://leetcode.com/problems/contain-virus/

*/
class Solution {
private:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,unordered_set<int>& virus,unordered_set<int>& toInfect,int& wall,int row,int col){
        int m=grid.size(),n=grid[0].size(),N=100;
        if(row<0||row>=m||col<0||col>=n||visited[row][col]==1) return;
        if(grid[row][col]==1){
            visited[row][col]=1;
            virus.insert(row*N+col);
            vector<int> dir={0,-1,0,1,0};
            for(int i=0;i<4;i++)
                dfs(grid,visited,virus,toInfect,wall,row+dir[i],col+dir[i+1]);
        }else if(grid[row][col]==0){
            wall++;
            toInfect.insert(row*N+col);
        }
    }
    int model(vector<vector<int>>& grid){
        int m=grid.size(),n=grid[0].size(),N=100;
        vector<unordered_set<int>> virus,toInfect;
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<int> walls;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&visited[i][j]==0){
                    virus.push_back(unordered_set<int>());
                    toInfect.push_back(unordered_set<int>());
                    walls.push_back(0);
                    dfs(grid,visited,virus.back(),toInfect.back(),walls.back(),i,j);
                }
            }
        }
        int maxArea=0,idx=-1;
        for(int i=0;i<toInfect.size();i++){
            if(toInfect[i].size()>maxArea){
                maxArea=toInfect[i].size();
                idx=i;
            }
        }
        if(idx==-1) return 0;
        for(int i=0;i<toInfect.size();i++){
            if(i!=idx){
                for(int key:toInfect[i])
                    grid[key/N][key%N]=1;
            }else{
                for(int key:virus[i])
                    grid[key/N][key%N]=-1;
            }
        }
        return walls[idx];
    }
public:
    int containVirus(vector<vector<int>>& grid) {
        int res=0;
        while(true){
            int walls=model(grid);
            if(walls==0) break;
            res+=walls;
        }
        return res;
    }
};
