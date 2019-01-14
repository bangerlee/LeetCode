/*
https://leetcode.com/problems/find-peak-element/

Runtime: 4 ms
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo=0,hi=nums.size()-1;
        while(lo<hi){
            int mid=(lo+hi)/2;
            int midf=mid+1;
            if(nums[midf]>nums[mid]) lo=midf;
            else hi=mid;
        }
        return lo;
    }
};
