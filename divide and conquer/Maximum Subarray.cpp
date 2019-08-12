/*
https://leetcode.com/problems/maximum-subarray/

*/
class Solution {
private:
    int maxSub(vector<int>& nums,int l,int r){
        if(l>r) return INT_MIN;
        int mid=l+(r-l)/2,lmax=maxSub(nums,l,mid-1),rmax=maxSub(nums,mid+1,r);
        int s1=0,s2=0;
        for(int i=mid-1,cur=0;i>=l;i--){
            cur+=nums[i];
            s1=max(s1,cur);
        }
        for(int i=mid+1,cur=0;i<=r;i++){
            cur+=nums[i];
            s2=max(s2,cur);
        }
        return max(s1+s2+nums[mid],max(lmax,rmax));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return maxSub(nums,0,nums.size()-1);
    }
};
