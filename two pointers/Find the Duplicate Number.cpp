/*
https://leetcode.com/problems/find-the-duplicate-number/

*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0,res=0;
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast) break;
        }
        while(slow!=res){
            slow=nums[slow];
            res=nums[res];
        }
        return res;
    }
};
