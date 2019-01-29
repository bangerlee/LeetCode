/*
https://leetcode.com/problems/product-of-array-except-self/

*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0]=1;
        for(int i=1;i<nums.size();i++)
            res[i]=nums[i-1]*res[i-1];
        int r=1;
        for(int j=nums.size()-1;j>=0;j--){
            res[j]*=r;
            r*=nums[j];
        }
        return res;
    }
};
