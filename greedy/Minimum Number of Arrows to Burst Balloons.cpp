/*
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

*/
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(),points.end(),[](pair<int,int>& a,pair<int,int>& b)
             {
                if(a.second==b.second) return b.first>a.first;
                 else return b.second>a.second;
             });
        int res=1,end=points[0].second;
        for(int i=1;i<points.size();i++){
            if(points[i].first>end){
                res++;
                end=points[i].second;
            }
        }
        return res;
    }
};
