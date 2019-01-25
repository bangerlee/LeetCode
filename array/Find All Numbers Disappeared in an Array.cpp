/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int val=abs(nums[i])-1;
            if(nums[val]>0) nums[val]=-nums[val];
        }
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0) res.push_back(i+1);
        return res;
    }
};
