/*
https://leetcode.com/problems/previous-permutation-with-one-swap/

*/
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n=A.size(),i=n-2;
        for(;i>=0;i--)
            if(A[i]>A[i+1]) break;
        if(i<0) return A;
        int j=n-1;
        while(A[j]>=A[i]) j--;
        while(A[j]==A[j-1]) j--;
        swap(A[i],A[j]);
        return A;
    }
};
