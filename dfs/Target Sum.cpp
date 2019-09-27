/*
https://leetcode.com/problems/target-sum/

*/
class Solution {
private:
    int res=0;
    void helper(vector<int>& nums,int target,int pos,long eval){
        if(pos==nums.size()){
            if(target==eval) res++;
            return;
        }
        helper(nums,target,pos+1,eval+nums[pos]);
        helper(nums,target,pos+1,eval-nums[pos]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size()==0) return res;
        helper(nums,S,0,0);
        return res;
    }
};
