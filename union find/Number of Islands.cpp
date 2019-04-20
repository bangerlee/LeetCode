/*
https://leetcode.com/problems/number-of-islands/

*/
class UnionFind {
    vector<int> father;
    int m,n;
public:
    int count=0;
    UnionFind(vector<vector<char>>& grid){
        m=grid.size(),n=grid[0].size();
        father.resize(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    int id=i*n+j;
                    father[id]=id;
                    count++;
                }
            }
        }
    }
    void my_union(int node1,int node2){
        int find1=find(node1);
        int find2=find(node2);
        if(find1==find2) return;
        father[find1]=find2;
        count--;
    }
    int find(int node){
        if(father[node]==node) return node;
        father[node]=find(father[node]);
        return father[node];
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> dis={{1,0},{-1,0},{0,1},{0,-1}};
        if(grid.size()==0 || grid[0].size()==0) return 0;
        UnionFind uf(grid);
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    for(auto d:dis){
                        int x=i+d[0],y=j+d[1];
                        if(x<0||y<0||x>=m||y>=n||grid[x][y]!='1') continue;
                        int id1=i*n+j,id2=x*n+y;
                        uf.my_union(id1,id2);
                    }
                }
            }
        }
        return uf.count;
    }
};
