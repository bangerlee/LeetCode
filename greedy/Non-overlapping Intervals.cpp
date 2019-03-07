/*
https://leetcode.com/problems/non-overlapping-intervals/

*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),[](Interval& a,Interval& b){
            if(a.end==b.end) return b.start>a.start;
            else return b.end>a.end;
        });
        int res=1,end=intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start>=end){
                end=intervals[i].end;
                res++;
            }
        }
        return intervals.size()-res;
    }
};
