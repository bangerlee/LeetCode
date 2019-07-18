/*
https://leetcode.com/problems/minimum-number-of-refueling-stops/
*/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i=0, res=0,cur=startFuel;
        priority_queue<int> pq;
        for(;cur<target;res++){
            while(i<stations.size() && stations[i][0]<=cur) pq.push(stations[i++][1]);
            if(pq.empty()) return -1;
            cur+=pq.top();pq.pop();
        }
        return res;
    }
};
