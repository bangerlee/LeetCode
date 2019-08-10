/*
https://leetcode.com/problems/maximum-gap/

*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int mmin=*min_element(nums.begin(),nums.end());
        int mmax=*max_element(nums.begin(),nums.end());
        int gap=(int)ceil((double)(mmax-mmin)/(nums.size()-1));
        vector<int> min_buckets(nums.size()-1,INT_MAX);
        vector<int> max_buckets(nums.size()-1,INT_MIN);
        for(auto& k:nums){
            if(k==mmin||k==mmax) continue;
            int idx=(k-mmin)/gap;
            min_buckets[idx]=min(k,min_buckets[idx]);
            max_buckets[idx]=max(k,max_buckets[idx]);
        }
        int res=INT_MIN,prev=mmin;
        for(int i=0;i<nums.size()-1;i++){
            if(min_buckets[i]==INT_MAX && max_buckets[i]==INT_MIN) continue;
            res=max(res,min_buckets[i]-prev);
            prev=max_buckets[i];
        }
        res=max(res,mmax-prev);
        return res;
    }
};
