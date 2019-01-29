/*
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

The other important fact is that whenever we come across a value A[i] that is smaller than the current max, we know that the unsorted subarray AT LEAST needs to end here. Similarly, whenever we come across a value A[n-1-i] that is larger than the current min, we know that the unsorted subarray AT LEAST needs to start here.
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int sm=nums[nums.size()-1],mm=nums[0],b=-1,e=-2;
        for(int i=0;i<nums.size();i++){
            mm=max(mm,nums[i]);
            sm=min(sm,nums[nums.size()-i-1]);
            if(nums[i]<mm) e=i;
            if(nums[nums.size()-i-1]>sm) b=nums.size()-i-1;
        }
        return e-b+1;
    }
};
