/*
https://leetcode.com/problems/all-paths-from-source-lead-to-destination/

*/
class Solution {
bool dfs(vector<vector<int>>& al,vector<int>& visited,int i,int dest){
    if(al[i].empty()) return i==dest;
    if(visited[i]!=-1) return visited[i];
    visited[i]=0;
    for(auto& j:al[i])
        if(!dfs(al,visited,j,dest)) return false;
    return visited[i]=true;
}
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> al(n);
        vector<int> visited(n,-1);
        for(auto& e:edges) al[e[0]].push_back(e[1]);
        return dfs(al,visited,source,destination);
    }
};
