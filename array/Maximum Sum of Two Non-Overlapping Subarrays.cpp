/*
https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

*/
class Solution {
private:
    int getSubarraySum(vector<int>& sum,int i,int j){
        if(i==0) return sum[j];
        return sum[j]-sum[i-1];
    }
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> sum(A.size(),0);
        int res=0;
        sum[0]=A[0];
        int N=A.size();
        for(int i=1;i<N;i++) sum[i]=sum[i-1]+A[i];
        for(int i=L;i<=N;i++){
            int p=getSubarraySum(sum,i-L,i-1);
            for(int j=i+M;j<=N;j++){
                int q=getSubarraySum(sum,j-M,j-1);
                res=max(res,p+q);
            }
        }
        for(int i=M;i<=N;i++){
            int p=getSubarraySum(sum,i-M,i-1);
            for(int j=i+L;j<=N;j++){
                int q=getSubarraySum(sum,j-L,j-1);
                res=max(res,p+q);
            }
        }
        return res;
    }
};
