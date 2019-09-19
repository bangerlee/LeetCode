/*
https://leetcode.com/problems/redundant-connection/

*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> v(edges.size()+1,0);
        for(auto e:edges){
            int p0=e[0],p1=e[1];
            while(v[p0]) p0=v[p0];
            while(v[p1]) p1=v[p1];
            if(p0==p1) return e;
            v[p0]=p1;
        }
        return vector<int>{-1,-1};
    }
};
