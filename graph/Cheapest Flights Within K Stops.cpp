/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/

*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> v(n,1e8);
        v[src]=0;
        for(int i=0;i<=K;i++){
            vector<int> tmp(v);
            for(auto& flight:flights)
                tmp[flight[1]]=min(tmp[flight[1]],v[flight[0]]+flight[2]);
            v=tmp;
        }
        return v[dst]==1e8?-1:v[dst];
    }
};
