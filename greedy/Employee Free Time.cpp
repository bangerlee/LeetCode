/*
https://leetcode.com/problems/employee-free-time/

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
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>>& schedule) {
        vector<Interval*> res,timeLine;
        for(int i=0;i<schedule.size();i++){
            for(int j=0;j<schedule[i].size();j++) timeLine.push_back(schedule[i][j]);
        }
        sort(timeLine.begin(),timeLine.end(),[](Interval* a,Interval* b){
            return b->start > a->start; 
        });
        Interval* tmp=timeLine[0];
        for(Interval* cur:timeLine){
            if(tmp->end < cur->start){
                res.push_back(new Interval(tmp->end,cur->start));
                tmp=cur;
            }else tmp=tmp->end < cur->end?cur:tmp;
        }
        return res;
    }
};
