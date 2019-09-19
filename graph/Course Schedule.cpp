/*
https://leetcode.com/problems/course-schedule/

*/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto x:prerequisites){
            adj[x.second].push_back(x.first);
            indegree[x.first]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
            if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            numCourses--;
            for(auto next:adj[cur])
                if(--indegree[next]==0) q.push(next);
        }
        return numCourses==0;
    }
};
