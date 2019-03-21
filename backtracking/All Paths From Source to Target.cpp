/*
https://leetcode.com/problems/all-paths-from-source-to-target/

*/
class Solution {
private:
    void helper(vector<vector<int>>& res,vector<vector<int>>& graph,vector<int>& p,int cur){
        p.push_back(cur);
        if(cur==graph.size()-1) res.push_back(p);
        else for(auto it:graph[cur]) helper(res,graph,p,it);
        p.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> p;
        helper(res,graph,p,0);
        return res;
    }
};
