/*
https://leetcode.com/problems/split-array-largest-sum/

*/
class Solution {
private:
    bool valid(long mid,vector<int>& nums,int m){
        int count=1;
        long total=0;
        for(auto x:nums){
            total+=x;
            if(total>mid){
                count++;
                total=x;
            }
            if(count>m) return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int imax=0;
        long sum=0;
        for(auto x:nums) imax=max(imax,x),sum+=x;
        if(m==1) return sum;
        long l=imax,r=sum;
        while(l<=r){
            long mid=(r+l)/2;
            if(valid(mid,nums,m)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
