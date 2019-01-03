/*
https://leetcode.com/problems/3sum/

Runtime: 112 ms
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            l=i+1;
            r=nums.size()-1;
            while(l<r){
                int tmp=nums[i]+nums[l]+nums[r];
                if(tmp>0) r--;
                else if(tmp<0) l++;
                else{
                    res.push_back(vector<int> {nums[i],nums[l],nums[r]});
                    while(nums[l]==nums[l+1]) l++;
                    while(nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};
