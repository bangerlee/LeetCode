/*
https://leetcode.com/problems/brick-wall/
*/
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> m;
        int res=wall.size();
        for(auto a:wall){
            for(int j=0,width=0;j<a.size()-1;j++){
                width+=a[j];
                m[width]++;
            }
        }
        auto it=m.begin();
        while(it!=m.end()){
            int tmp=wall.size()-it->second;
            res=min(res,tmp);
            it++;
        }
        return res;
    }
};
