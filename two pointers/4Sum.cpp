/*
https://leetcode.com/problems/4sum/

*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        vector<vector<int>> res;
        if(nums.size()<4) return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                l=j+1;
                r=nums.size()-1;
                while(l<r){
                    int tmp=nums[i]+nums[j]+nums[l]+nums[r];
                    if(tmp<target) l++;
                    else if(tmp>target) r--;
                    else{
                        vector<int> v{nums[i],nums[j],nums[l],nums[r]};
                        if(find(res.begin(),res.end(),v)==res.end())
                        res.push_back(v);
                        while(l<r&&nums[l]==nums[l+1]) l++;
                        while(l<r&&nums[r]==nums[r-1]) r--;
                        l++,r--;
                    }
                }
            }
        }
        return res;
    }
};
