/*
https://leetcode.com/problems/max-consecutive-ones-ii/

*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,q=-1,h=0,res=0;
        for(;h<nums.size();h++){
            if(nums[h]==0){
                l=q+1;
                q=h;
            }
            res=max(res,h-l+1);
        }
        return res;
    }
};
