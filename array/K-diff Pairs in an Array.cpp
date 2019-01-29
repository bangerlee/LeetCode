/*
https://leetcode.com/problems/k-diff-pairs-in-an-array/

*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,res=0;
        for(int j=1;j<nums.size();){
            if(nums[j]-nums[i]<k||i>=j) j++;
            else if(i>0&&nums[i]==nums[i-1]||(nums[j]-nums[i]>k)) i++;
            else
                res++,i++;
        }
        return res;
    }
};
