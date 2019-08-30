/*
https://leetcode.com/problems/non-overlapping-intervals/

*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
           if(b[1]==a[1]) return b[0]>a[0];
            return b[1]>a[1];
        });
        int res=1,end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=end){
                end=intervals[i][1];
                res++;
            }
        }
        return intervals.size()-res;
    }
};
