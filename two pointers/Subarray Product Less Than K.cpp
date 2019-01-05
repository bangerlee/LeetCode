/*
https://leetcode.com/problems/subarray-product-less-than-k/

Runtime: 132 ms
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res=0,product=1,i=0;
        if(k==0) return 0;
        for(int j=0;j<nums.size();j++){
            product*=nums[j];
            while(i<=j&&product>=k)
                product/=nums[i++];
            res+=j-i+1;
        }
        return res;
    }
};
