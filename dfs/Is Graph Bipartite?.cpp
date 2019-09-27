/*
https://leetcode.com/problems/is-graph-bipartite/

*/
class Solution {
private:
    bool canColor(vector<vector<int>>& graph,vector<int>& colored,int c,int idx){
        if(colored[idx]!=0) return colored[idx]==c;
        colored[idx]=c;
        for(auto& k:graph[idx])
            if(!canColor(graph,colored,-c,k)) return false;
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colored(graph.size(),0);
        for(int i=0;i<graph.size();i++)
            if(colored[i]==0&&!canColor(graph,colored,1,i)) return false;
        return true;
    }
};
