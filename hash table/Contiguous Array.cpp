/*
https://leetcode.com/problems/contiguous-array/

hashmap+prefix sum
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) if(nums[i]==0) nums[i]=-1;
        int sum=0,res=0;
        unordered_map<int,int> m;
        m.insert({0,-1});
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(m.count(sum)) res=max(res,i-m[sum]);
            else m.insert({sum,i});
        }
        return res;
    }
};
