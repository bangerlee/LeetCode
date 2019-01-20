/*
https://leetcode.com/problems/subarray-sum-equals-k/

prefix sum
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k) res++;
            int tmp=nums[i];
            for(int j=i+1;j<nums.size();j++){
                tmp+=nums[j];
                if(tmp==k) res++;
            }
        }
        return res;
    }
};
