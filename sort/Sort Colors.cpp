/*
https://leetcode.com/problems/sort-colors/

*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int b=0,e=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            while(nums[i]==2&&i<e) swap(nums[i],nums[e--]);
            while(nums[i]==0&&i>b) swap(nums[i],nums[b++]);
        }
    }
};
