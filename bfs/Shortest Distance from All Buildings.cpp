/*
https://leetcode.com/problems/shortest-distance-from-all-buildings/

*/
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.size()==0||grid[0].size()==0) return 0;
        vector<int> dir={0,1,0,-1,0};
        
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>> distance(row,vector<int>(col,0));
        vector<vector<int>> reach(row,vector<int>(col,0));
        int buildingnum=0;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    buildingnum++;
                    queue<vector<int>> q;
                    q.push({i,j});
                    
                    vector<vector<bool>> visited(row,vector<bool>(col,false));
                    int level=1;
                    
                    while(!q.empty()){
                        int qSize=q.size();
                        for(int l=0;l<qSize;l++){
                            vector<int> cur=q.front();q.pop();
                            for(int k=0;k<4;k++){
                                int nextRow=cur[0]+dir[k];
                                int nextCol=cur[1]+dir[k+1];
                            
                                if(nextRow>=0&&nextRow<row&&nextCol>=0&&nextCol<col&&grid[nextRow][nextCol]==0&&!visited[nextRow][nextCol]){
                                    distance[nextRow][nextCol]+=level;
                                    reach[nextRow][nextCol]++;
                                    visited[nextRow][nextCol]=true;
                                    q.push({nextRow,nextCol});
                                }
                            }
                        }
                        level++;
                    }
                }
            }
        }
        int res=INT_MAX;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0&&reach[i][j]==buildingnum)
                    res=min(res,distance[i][j]);
            }
        }
        return res==INT_MAX?-1:res;
    }
};
