/*
https://leetcode.com/problems/third-maximum-number/

*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int x:nums){
            s.insert(x);
            if(s.size()>3) s.erase(s.begin());
        }
        return s.size()>=3?*s.begin():*s.rbegin();
    }
};
