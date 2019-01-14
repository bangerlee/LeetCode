/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Runtime: 8 ms
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<int> res(2,-1);
        if(nums.size()==0) return res;
        while(i<j){
            int mid=(i+j)/2;
            if(nums[mid]<target) i=mid+1;
            else j=mid;
        }
        if(nums[i]!=target) return res;
        res[0]=i;
        j=nums.size()-1;
        while(i<j){
            int mid=(i+j)/2+1;
            if(nums[mid]>target) j=mid-1;
            else i=mid;
        }
        res[1]=j;
        return res;
    }
};
