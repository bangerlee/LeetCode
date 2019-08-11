/*
https://leetcode.com/problems/insert-interval/

*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        if(intervals.size()==1) return intervals;
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return b[0]>a[0];
        });
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>res.back()[1]) res.push_back(intervals[i]);
            else res.back()[1]=max(res.back()[1],intervals[i][1]);
        }
        return res;
    }
};
