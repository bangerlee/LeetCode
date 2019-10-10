/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();){
            nums[i++]=nums[j++];
            while(j<nums.size()&&j>0&&nums[j]==nums[j-1]) j++;
        }
        return i;
    }
};
