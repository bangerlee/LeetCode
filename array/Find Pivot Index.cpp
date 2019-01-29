/*
https://leetcode.com/problems/find-pivot-index/

*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,i=0,s=0;
        for(int x:nums) sum+=x;
        for(;i<nums.size();s+=nums[i++]){
            if(s*2==sum-nums[i]) return i;
        }
        return -1;
    }
};
