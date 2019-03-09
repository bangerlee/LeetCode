/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/

*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> distence(n,1e8);
        distence[src]=0;
        for(int i=0;i<=K;i++){
            vector<int> tmp(distence);
            for(auto x:flights){
                tmp[x[1]]=min(tmp[x[1]], distence[x[0]]+x[2]);
            }
            distence=tmp;
        }
        return distence[dst]==1e8?-1:distence[dst];
    }
};
