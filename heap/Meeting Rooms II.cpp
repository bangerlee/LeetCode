/*
https://leetcode.com/problems/meeting-rooms-ii/

*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){
            return b[0]>a[0];
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto interval:intervals){
            if(!pq.empty() && pq.top()<=interval[0]) pq.pop();
            pq.push(interval[1]);
        }
        return pq.size();
    }
};
