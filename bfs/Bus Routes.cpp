/*
https://leetcode.com/problems/bus-routes/

*/
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int,unordered_set<int>> to_route;
        for(int i=0;i<routes.size();i++)
            for(auto& j:routes[i]) to_route[j].insert(i);
        queue<pair<int,int>> q; q.push(make_pair(S,0));
        unordered_set<int> seen={S};
        while(!q.empty()){
            int stop=q.front().first,bus=q.front().second;q.pop();
            if(stop==T) return bus;
            for(auto& route_i: to_route[stop]){
                for(auto& next_stop: routes[route_i]){
                    if(!seen.count(next_stop)){
                        seen.insert(next_stop);
                        q.push(make_pair(next_stop,bus+1));
                    }
                }
                routes[route_i].clear();
            }
        }
        return -1;
    }
};
