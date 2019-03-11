/*
https://leetcode.com/problems/minimum-height-trees/

*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n==1) return vector<int>(1,0);
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        vector<int> leaves;
        for(int i=0;i<n;i++)
            if(adj[i].size()==1) leaves.push_back(i);
        while(n>2){
            n-=leaves.size();
            vector<int> new_leaves;
            for(int i:leaves){
                int next=adj[i][0];
                auto it=find(adj[next].begin(),adj[next].end(),i);
                adj[next].erase(it);
                if(adj[next].size()==1) new_leaves.push_back(next);
            }
            leaves=new_leaves;
        }
        return leaves;
    }
};
