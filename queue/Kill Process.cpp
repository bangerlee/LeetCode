/*
https://leetcode.com/problems/kill-process/
*/
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        unordered_map<int,unordered_set<int>> m;
        for(int i=0;i<pid.size();i++) m[ppid[i]].insert(pid[i]);
        queue<int> q;
        q.push(kill);
        while(!q.empty()){
            int p=q.front();q.pop();
            res.push_back(p);
            for(auto child:m[p]) q.push(child);
        }
        return res;
    }
};
