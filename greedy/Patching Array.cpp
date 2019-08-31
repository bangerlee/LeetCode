/*
https://leetcode.com/problems/patching-array/

*/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res=0,i=0;
        long long maxNum=0;
        while(maxNum<n){
            if(i<nums.size()&&nums[i]<=maxNum+1) maxNum+=nums[i++];
            else{
                maxNum+=maxNum+1;
                res++;
            }
        }
        return res;
    }
};
