/*
https://leetcode.com/problems/freedom-trail/

*/
class Solution {
int dfs(string& ring,string& key,unordered_map<char,unordered_set<int>>& mp,
        vector<vector<int>>& memo,int ridx,int kidx){
    if(kidx==key.size()) return 0;
    if(memo[ridx][kidx]) return memo[ridx][kidx];
    int res=INT_MAX;
    for(int nextidx:mp[key[kidx]]){
        int diff=abs(nextidx-ridx);
        int step=min(diff,(int)ring.size()-diff);
        res=min(res,dfs(ring,key,mp,memo,nextidx,kidx+1)+step);
    }
    memo[ridx][kidx]=res;
    return res;
}
public:
    int findRotateSteps(string ring, string key) {
        int rlen=ring.size(),klen=key.size();
        unordered_map<char,unordered_set<int>> mp;
        for(int i=0;i<rlen;i++) mp[ring[i]].insert(i);
        vector<vector<int>> memo(rlen,vector<int>(klen,0));
        return dfs(ring,key,mp,memo,0,0)+klen;
    }
};
