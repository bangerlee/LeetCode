/*
https://leetcode.com/problems/minimum-area-rectangle/
*/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int,int>> sp;
        int res=INT_MAX;
        for(auto point:points)
            sp.insert({point[0],point[1]});
        for(auto point0:points){
            for(auto point1:points){
                if(point0[0]==point1[0]||point0[1]==point1[1]) continue;
                if(sp.count({point0[0],point1[1]})&&sp.count({point1[0],point0[1]}))
                    res=min(res,abs((point0[0]-point1[0])*(point0[1]-point1[1])));
            }
        }
        return res==INT_MAX?0:res;
    }
};
