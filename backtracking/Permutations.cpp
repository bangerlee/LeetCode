/*
https://leetcode.com/problems/permutations/

*/
class Solution {
private:
    void bkt(vector<int>& nums,vector<vector<int>>& res,int begin){
        if(begin>=nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            swap(nums[begin],nums[i]);
            bkt(nums,res,begin+1);
            swap(nums[begin],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        bkt(nums,res,0);
        return res;
    }
};
