/*
https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

*/
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int psum=0,res=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            psum+=nums[i];
            if(psum==k) res=i+1;
            else if(m.count(psum-k)) res=max(res,i-m[psum-k]);
            if(!m.count(psum)) m.insert({psum,i});
        }
        return res;
    }
};
