/*
https://leetcode.com/problems/as-far-from-land-as-possible/

*/
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size(),n=grid[0].size(),res=-1;
        vector<vector<int>> dirs={{0,1},{0,-1},{-1,0},{1,0}};
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) 
                if(grid[i][j]) q.push({i,j});
        if(q.empty()||m*n==q.size()) return -1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto p=q.front();q.pop();
                for(auto& d:dirs){
                    int x=p.first+d[0],y=p.second+d[1];
                    if(x<0||y<0||x>=m||y>=m||grid[x][y]==1) continue;
                    q.push({x,y});
                    grid[x][y]=1;
                }
            }
            res++;
        }
        return res;
    }
};
