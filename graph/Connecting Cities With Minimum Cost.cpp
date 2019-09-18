/*
https://leetcode.com/problems/connecting-cities-with-minimum-cost/

*/
class Solution {
private:
    vector<int> parent;
    int n;
    void myunion(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px!=py){
            parent[px]=py;
            n--;
        }
    }
    int find(int x){
        if(parent[x]==x) return x;
        parent[x]=find(parent[x]);
        return parent[x];
    }
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        parent=vector<int>(N+1,0);
        n=N;
        for(int i=0;i<=N;i++) parent[i]=i;
        sort(connections.begin(),connections.end(),[](vector<int>& a,vector<int>& b){
           return b[2]>a[2]; 
        });
        int res=0;
        for(vector<int>& k:connections){
            int x=k[0],y=k[1];
            if(find(x)!=find(y)){
                res+=k[2];
                myunion(x,y);
            }
        }
        return n==1?res:-1;
    }
};
