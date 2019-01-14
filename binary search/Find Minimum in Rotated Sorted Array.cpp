/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Runtime: 4 ms
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<j){
            int mid=i+(j-i)/2;
            if(nums[i]<nums[j]) return nums[i];
            if(nums[mid]>=nums[i]) i=mid+1;       
            else j=mid;
        }
        return nums[i];
    }
};
