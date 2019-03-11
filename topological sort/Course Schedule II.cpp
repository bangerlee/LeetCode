/*
https://leetcode.com/problems/course-schedule-ii/

*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> degree(numCourses,0);
        vector<int> res;
        for(auto x:prerequisites){
            adj[x.second].push_back(x.first);
            degree[x.first]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(degree[i]==0){
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
            int cur=q.front();q.pop();numCourses--;
            for(int next:adj[cur])
                if(--degree[next]==0){ 
                    q.push(next);
                    res.push_back(next);
                }
        }
        if(numCourses==0) return res;
        return vector<int>(0);
    }
};
