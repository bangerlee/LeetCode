/*
https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/

*/
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1,idx=0;
        while(i<j){
            int mid=(i+j)/2;
            if(nums[mid]<target) i=mid+1;
            else j=mid;
        }
        if(nums[i]!=target) return false;
        idx=i;
        j=nums.size()-1;
        while(i<j){
            int mid=(i+j)/2+1;
            if(nums[mid]>target) j=mid-1;
            else i=mid;
        }
        return j-idx+1>nums.size()/2;
    }
};
