/*
https://leetcode.com/problems/heaters/submissions/

Runtime: 80 ms
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        vector<int> v(houses.size(),INT_MAX);
        for(int p=0,q=0;p<houses.size()&&q<heaters.size();){
            if(houses[p]<=heaters[q]){
                v[p]=heaters[q]-houses[p];
                p++;
            }
            else q++;
        }
        for(int p=houses.size()-1,q=heaters.size()-1;p>=0&&q>=0;){
            if(houses[p]>=heaters[q]){
                v[p]=min(v[p],houses[p]-heaters[q]);
                p--;
            }
            else q--;
        }
        return *max_element(v.begin(),v.end());
    }
};
