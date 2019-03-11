/*
https://leetcode.com/problems/graph-valid-tree/

*/
class Solution {
private:
    int find(vector<int>&num,int i){
        if(num[i]==-1) return i;
        return find(num,num[i]);
    }
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> num(n,-1);
        for(auto edge:edges){
            int x=find(num,edge.first);
            int y=find(num,edge.second);
            if(x==y) return false;
            num[x]=y;
        }
        return n-1==edges.size();
    }
};
