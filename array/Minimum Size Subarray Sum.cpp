/*
https://leetcode.com/problems/minimum-size-subarray-sum/

*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> psum(nums.size()+1,0);
        for(int i=0;i<nums.size();i++) psum[i+1]=nums[i]+psum[i];
        int res=INT_MAX;
        for(int l=0,r=1;r<psum.size();r++){
            while(r<psum.size()&&psum[r]-psum[l]<s) r++;
            r=r==psum.size()?r-1:r;
            while(l<r&&psum[r]-psum[l+1]>=s) l++;
            if(psum[r]-psum[l]>=s) res=min(res,r-l);
        }
        return res==INT_MAX?0:res;
    }
};
