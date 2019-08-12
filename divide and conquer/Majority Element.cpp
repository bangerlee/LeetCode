/*
https://leetcode.com/problems/majority-element/

*/
class Solution {
private:
    int majority(vector<int>& nums,int l,int r){
        if(l==r) return nums[l];
        int m=l+(r-l)/2,lm=majority(nums,l,m),rm=majority(nums,m+1,r);
        if(lm==rm) return lm;
        return count(nums.begin()+l,nums.begin()+r+1,lm) > count(nums.begin()+l,nums.begin()+r+1,rm)?lm:rm;
    }
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums,0,nums.size()-1);
    }
};
