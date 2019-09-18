/*
https://leetcode.com/problems/parallel-courses/

*/
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        unordered_map<int,vector<int>> graph;
        vector<int> indegree(N+1,0);
        for(vector<int>& r:relations){
            graph[r[0]].push_back(r[1]);
            ++indegree[r[1]];
        }
        queue<int> q;
        for(int i=1;i<=N;i++)
            if(indegree[i]==0) q.push(i);
        int res=0;
        while(!q.empty()){
            for(int size=q.size();size>0;size--){
                int c=q.front();q.pop();
                --N;
                if(!graph.count(c)) continue;
                for(int course:graph[c]){
                    if(--indegree[course]==0) q.push(course);
                }
            }
            ++res;
        }
        return N==0?res:-1;
    }
};
