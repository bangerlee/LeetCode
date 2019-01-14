/*
https://leetcode.com/problems/find-k-th-smallest-pair-distance/

Runtime: 12 ms
*/
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int lo=0,hi=nums.back()-nums[0]+1;
        while(lo<hi){
            int mid=(lo+hi)/2;
            int count=0;
            for(int i=0,j=1;i<=j&&j<n;){
                if(nums[j]-nums[i]<=mid){
                    count+=j-i;
                    j++;
                }
                else i++;
            }
            if(count<k) lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
};
