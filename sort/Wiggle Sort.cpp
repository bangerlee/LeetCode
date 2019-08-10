/*
https://leetcode.com/problems/wiggle-sort/

*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i%2==1){
                if(nums[i-1]>nums[i]) swap(nums[i-1],nums[i]);
            }
            else{
                if(i!=0&&nums[i]>nums[i-1]) swap(nums[i],nums[i-1]);
            }
        }
    }
};
