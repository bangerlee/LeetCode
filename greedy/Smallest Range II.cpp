/*
https://leetcode.com/problems/smallest-range-ii/

*/
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int n=A.size(),mx=A[n-1],mn=A[0],res=mx-mn;
        for(int i=0;i<n-1;i++){
            mx=max(mx,A[i]+2*K);
            mn=min(A[0]+2*K,A[i+1]);
            res=min(res,mx-mn);
        }
        return res;
    }
};
