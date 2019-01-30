/*
https://leetcode.com/problems/continuous-subarray-sum/

This is one of those magics of remainder theorem :)

(a+(n*x))%x is same as (a%x)

For e.g. in case of the array [23,2,6,4,7] the running sum is [23,25,31,35,42] and the remainders are [5,1,1,5,0]. We got remainder 5 at index 0 and at index 3. That means, in between these two indexes we must have added a number which is multiple of the k. Hope this clarifies your doubt :)
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        if (k == 0) k = INT_MAX;
        int sum = 0;
        unordered_map<int, int> map;
        map[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum%=k;
            if (map.find(sum) == map.end()) {
                map[sum] = i;
            } else {
                if (i - map[sum] > 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
