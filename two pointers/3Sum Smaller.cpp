/*
https://leetcode.com/problems/3sum-smaller/

*/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res=0,len=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++){
            int left=i+1,right=len-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]<target){
                    res+=right-left;
                    left++;
                }
                else right--;
            }
        }
        return res;
    }
};
