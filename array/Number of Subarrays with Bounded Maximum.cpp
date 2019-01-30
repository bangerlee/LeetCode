/*
https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

*/
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int j=0,count=0,res=0;
        for(int i=0;i<A.size();i++){
            if(A[i]>R){
                count=0;
                j=i+1;
            }
            else if(A[i]>=L) count=i-j+1;
            res+=count;
        }
        return res;
    }
};
