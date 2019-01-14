/*
https://leetcode.com/problems/binary-search/

Runtime: 32 ms
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                j=mid-1;
            else
                i=mid+1;
        }
        return -1;
    }
};
