/*
https://leetcode.com/problems/longest-increasing-subsequence/

Runtime: 4 ms
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v(nums.size());
        int size=0;
        for(int x:nums){
            int i=0,j=size;
            while(i<j){
                int mid=(i+j)/2;
                if(v[mid]<x) i=mid+1;
                else j=mid;
            }
            v[i]=x;
            if(i==size) size++;
        }
        return size;
    }
};
