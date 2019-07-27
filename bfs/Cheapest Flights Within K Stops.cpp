/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/

*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int,int>>> m;
        for(auto& flight:flights) m[flight[0]].push_back({flight[1],flight[2]});
        int res=INT_MAX;
        queue<pair<int,int>> q;
        q.push({src,0});
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> stop=q.front();q.pop();
                if(stop.first==dst) res=min(res, stop.second);
                for(auto x:m[stop.first]){
                    if(stop.second+x.second>res) continue;
                    q.push({x.first,stop.second+x.second});
                }
            }
            if(steps++ > K) break;
        }
        return res==INT_MAX?-1:res;
    }
};
