/*
https://leetcode.com/problems/sequence-reconstruction/

*/
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        vector<vector<int>> adj(org.size()+1);
        vector<int> indegree(org.size()+1,0);
        bool empty=true;
        for(auto seq:seqs){
            if(seq.size()==0) continue;
            else empty=false;
            if(seq[0]<1||seq[0]>org.size()) return false;
            for(int i=0;i<seq.size()-1;i++){
                if(seq[i+1]<1||seq[i+1]>org.size()||seq[i]<1||seq[i]>org.size()) return false;
                adj[seq[i]].push_back(seq[i+1]);
                indegree[seq[i+1]]++;
            }
        }
        if(empty) return false;
        queue<int> q;
        vector<int> res;
        for(int i=1;i<indegree.size();i++)
            if(indegree[i]==0){
                q.push(i);
                res.push_back(i);
            }
        int idx=0;
        while(!q.empty()){
            if(q.size()!=1) return false;
            int cur=q.front();q.pop();
            if(cur!=org[idx++]) return false;
            for(int next:adj[cur]){
                if(--indegree[next]==0){
                    q.push(next);
                    res.push_back(next);
                }
            }
        }
        return idx==org.size();
    }
};
