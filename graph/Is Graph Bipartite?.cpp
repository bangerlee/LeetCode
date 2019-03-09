/*
https://leetcode.com/problems/is-graph-bipartite/

*/
class Solution {
private:
    bool validColor(vector<vector<int>>& graph,int idx,vector<int>& colored,int color){
        if(colored[idx]!=0) return colored[idx]==color;
        colored[idx]=color;
        for(auto x:graph[idx])
            if(!validColor(graph,x,colored,-color)) return false;
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colored(n,0);
        for(int i=0;i<n;i++){
            if(colored[i]==0&&!(validColor(graph,i,colored,1)))
                return false;
        }
        return true;
    }
};
