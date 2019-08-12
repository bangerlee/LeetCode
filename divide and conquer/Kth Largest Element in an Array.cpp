/*
https://leetcode.com/problems/kth-largest-element-in-an-array/

*/
class Solution {
private:
    int quickSelect(vector<int>& nums,int lo,int hi,int k){
        int i=lo,j=hi,pivot=nums[hi];
        while(i<j) 
            if(nums[i++]>pivot) swap(nums[--i],nums[--j]);
        swap(nums[i],nums[hi]);
        int m=i-lo+1;
        if(m==k) return i;
        else if(m>k) return quickSelect(nums,lo,i-1,k);
        else return quickSelect(nums,i+1,hi,k-m);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int idx=quickSelect(nums,0,n-1,n-k+1);
        return nums[idx];
    }
};
