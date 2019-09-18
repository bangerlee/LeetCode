/*
https://leetcode.com/problems/optimize-water-distribution-in-a-village/

*/
class UnionFind{
private:
    vector<int> unionFind;
public:
    UnionFind(int N):unionFind(N){
        for(int i=0;i<N;i++) unionFind[i]=i;
    }
    void merge(int key1,int key2){
        key1=get(key1);
        key2=get(key2);
        if(key1==key2) return;
        unionFind[key2]=key1;
    }
    int get(int key){
        while(key!=unionFind[key])
            key=unionFind[key]=unionFind[unionFind[key]];
        return key;
    }
};
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for(int i=1;i<=n;i++)
            pipes.push_back({0,i,wells[i-1]});
        // Kruskal's algorithm
        UnionFind uf(n+1);
        sort(pipes.begin(),pipes.end(),[](auto& a,auto& b){
            return b[2]>a[2]; 
        });
        int res=0;
        for(auto& pipe:pipes){
            if(uf.get(pipe[0])!=uf.get(pipe[1])){
                res+=pipe[2];
                uf.merge(pipe[0],pipe[1]);
            }
        }
        return res;
    }
};
