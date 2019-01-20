/*
https://leetcode.com/problems/number-of-boomerangs/

*/
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res=0;
        for(int i=0;i<points.size();i++){
            unordered_map<long,int> m;
            for(int j=0;j<points.size();j++){
                if(i==j) continue;
                int dx=points[j].first-points[i].first;
                int dy=points[j].second-points[i].second;
                long k=dx*dx+dy*dy;
                ++m[k];
            }
            for(auto p:m)
                res+=p.second*(p.second-1);
        }
        return res;
    }
};
