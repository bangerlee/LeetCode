/*
https://leetcode.com/problems/sort-colors/

*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int b=0,e=nums.size()-1;
        for(int i=0;i<=e;i++){
            while(i<e&&nums[i]==2) swap(nums[i],nums[e--]);
            while(i>b&&nums[i]==0) swap(nums[i],nums[b++]);
        }
    }
};
