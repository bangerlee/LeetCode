/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/submissions/

Runtime: 16 ms
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int n : nums){
            if(i<2||n>nums[i-2])
                nums[i++]=n;
        }
        return i;
    }
};
