/*
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

*/
class Solution {
private:
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(vector<vector<int>>& matrix,int i,int j,int m,int n,vector<vector<int>>& cache){
        if(cache[i][j]!=0) return cache[i][j];
        int res=1;
        for(auto p:dir){
            int x=i+p[0],y=j+p[1];
            if(x<0||y<0||x>=m||y>=n||matrix[i][j]>=matrix[x][y]) continue;
            res=max(res,1+dfs(matrix,x,y,m,n,cache));
        }
        cache[i][j]=res;
        return res;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return 0;
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> cache(m,vector<int>(n,0));
        int res=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res,dfs(matrix,i,j,m,n,cache));
            }
        }
        return res;
    }
};
