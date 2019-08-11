/*
https://leetcode.com/problems/count-of-range-sum/

*/
class Solution {
private:
    int sort_count(vector<long>& sums,int l,int r,int lower,int upper){
        if(r-l<=1) return 0;
        int m=(l+r)/2,i,j1,j2;
        int count=sort_count(sums,l,m,lower,upper)+sort_count(sums,m,r,lower,upper);
        for(int i=l,j1=j2=m;i<m;i++){
            while(j1<r && sums[j1]-sums[i]<lower) j1++;
            while(j2<r && sums[j2]-sums[i]<=upper) j2++;
            count+=j2-j1;
        }
        inplace_merge(sums.begin()+l,sums.begin()+m,sums.begin()+r);
        return count;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<long> sums(n+1,0);
        for(int i=0;i<n;i++) sums[i+1]=sums[i]+nums[i];
        return sort_count(sums,0,n+1,lower,upper);
    }
};
