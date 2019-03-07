/*
https://leetcode.com/problems/meeting-rooms-ii/

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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n==0) return 0;
        sort(intervals.begin(),intervals.end(),[](Interval &a,Interval &b){
            return b.start>a.start;
        });
        vector<bool> r(n,true);
        for(int i=0;i<n;i++){
            if(r[i]==false) continue;
            Interval tmp=intervals[i];
            for(int j=i+1;j<n;j++){
                if(r[j]==false) continue;
                if(intervals[j].start>=tmp.end){
                    tmp=intervals[j];
                    r[j]=false;
                }
            }
        }
        int res=0;
        for(bool x:r) if(x) res++;
        return res;
    }
};
