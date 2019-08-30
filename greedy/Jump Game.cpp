/*
https://leetcode.com/problems/jump-game/

*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int res=0;
        for(int i=0;i<=res;i++){
            res=max(res,i+nums[i]);
            if(res>=nums.size()-1) return true;
        }
        return false;
    }
};
