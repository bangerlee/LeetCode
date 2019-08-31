/*
https://leetcode.com/problems/jump-game-ii/

*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0,curEnd=0,curFarthest=0;
        for(int i=0;i<nums.size()-1;i++){
            curFarthest=max(curFarthest,i+nums[i]);
            if(i==curEnd){
                res++;
                curEnd=curFarthest;
            }
        }
        return res;
    }
};
