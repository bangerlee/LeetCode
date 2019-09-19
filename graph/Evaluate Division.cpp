/*
https://leetcode.com/problems/evaluate-division/

*/
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> graph;
        for(int i=0;i<equations.size();i++){
            string src=equations[i][0],dst=equations[i][1];
            graph[src].insert({src,1.0});
            graph[dst].insert({dst,1.0});
            graph[src].insert({dst,values[i]});
            graph[dst].insert({src,1/values[i]});
        }
        for(auto& it:graph){
            for(auto& p:it.second)
                for(auto& q:it.second){
                    double val=graph[p.first][it.first]*graph[it.first][q.first];
                    graph[p.first].insert({q.first,val});
                }
        }
        vector<double> res(queries.size());
        for(int i=0;i<res.size();i++){
            if(!graph.count(queries[i][0]) || !graph[queries[i][0]].count(queries[i][1])){
                res[i]=-1;
            }else{
                res[i]=graph[queries[i][0]][queries[i][1]];
            }
        }
        return res;
    }
};
