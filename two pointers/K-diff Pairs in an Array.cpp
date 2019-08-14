/*
https://leetcode.com/problems/k-diff-pairs-in-an-array/

*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res=0;
        sort(nums.begin(),nums.end());
        for(int i=0,j=0;i<nums.size();i++){
            for(j=max(j,i+1);j<nums.size()&&(long)nums[j]-nums[i]<k;j++);
            if(j<nums.size()&&(long)nums[j]-nums[i]==k) res++;
            while(i+1<nums.size()&&nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};
