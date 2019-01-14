/*
https://leetcode.com/problems/search-insert-position/

Runtime: 4 ms
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    }
};
