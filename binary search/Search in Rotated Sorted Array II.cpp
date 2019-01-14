/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

Runtime: 8 ms
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        if(nums.size()==0) return false;
        while(i<j){
            int mid=(i+j)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]>nums[i]){
                if(target<nums[mid]&&target>=nums[i]) j=mid;
                else i=mid+1;
            }
            else if(nums[mid]<nums[i]){
                if(target>nums[mid]&&target<=nums[j]) i=mid+1;
                else j=mid;
            }
            else i++;
        }
        return nums[i]==target?true:false;
    }
};
