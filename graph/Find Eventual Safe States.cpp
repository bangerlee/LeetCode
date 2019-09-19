/*
https://leetcode.com/problems/find-eventual-safe-states/

*/
class Solution {
private:
    bool helper(vector<vector<int>>& graph,int start,vector<int>& color){
        if(color[start]!=0) return color[start]==1;
        color[start]=2;
        for(auto x:graph[start])
            if(!helper(graph,x,color)) return false;
        color[start]=1;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int k=graph.size();
        vector<int> color(k,0);
        vector<int> res;
        for(int i=0;i<k;i++)
            if(helper(graph,i,color)) res.push_back(i);
        return res;
    }
};
