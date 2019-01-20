/*
https://leetcode.com/problems/binary-subarrays-with-sum/

prefix sum
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int res=0,sum=0;
        vector<int> v(A.size()+1,0);
        for(int x:A){
            sum+=x;
            if(sum==S) res++;
            if(sum-S>=0) res+=v[sum-S];
            v[sum]++;
        }
        return res;
    }
};
