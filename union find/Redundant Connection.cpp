/*
https://leetcode.com/problems/redundant-connection/

*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> v(edges.size()+1,0);
        for(auto x:edges){
            int p1=x[0],p2=x[1];
            while(v[p1]) p1=v[p1];
            while(v[p2]) p2=v[p2];
            if(p1==p2) return x;
            v[p1]=p2;
        }
        return vector<int>{-1,-1};
    }
};
