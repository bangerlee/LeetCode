/*
https://leetcode.com/problems/01-matrix/

*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0) q.push({i,j});
                else matrix[i][j]=INT_MAX;
            }
        }
        while(!q.empty()){
            pair<int,int> cell=q.front();q.pop();
            for(auto d:dir){
                int r=cell.first+d[0],c=cell.second+d[1];
                if(r<0||c<0||r>=m||c>=n||matrix[r][c]<=matrix[cell.first][cell.second]+1) continue;
                q.push({r,c});
                matrix[r][c]=matrix[cell.first][cell.second]+1;
            }
        }
        return matrix;
    }
};
