/*
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

*/
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res=0,mask=0;
        for(int i=31;i>=0;i--){
            mask=mask|(1<<i);
            set<int> s;
            for(auto num:nums) s.insert(num&mask);
            int tmp_max=res|(1<<i);
            for(auto leftnum:s){
                if(s.count(leftnum^tmp_max)){
                    res=tmp_max;
                    break;
                }
            }
        }
        return res;
    }
};
