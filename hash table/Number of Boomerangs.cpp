/*
https://leetcode.com/problems/number-of-boomerangs/

*/
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res=0;
        for(int i=0;i<points.size();i++){
            unordered_map<long,int> m;
            for(int j=0;j<points.size();j++){
                if(i==j) continue;
                int dx=points[j][0]-points[i][0];
                int dy=points[j][1]-points[i][1];
                long k=dx*dx+dy*dy;
                ++m[k];
            }
            for(auto& p:m) res+=p.second*(p.second-1);
        }
        return res;
    }
};
