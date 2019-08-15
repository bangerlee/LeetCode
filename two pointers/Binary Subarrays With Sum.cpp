/*
https://leetcode.com/problems/binary-subarrays-with-sum/

*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int left=0,sum=0,n=A.size(),res=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            while(left<i&&sum>S) sum-=A[left++];
            if(sum<S) continue;
            if(sum==S) res++;
            int t=left;
            while(t<i&&A[t]==0) t++,res++;
        }
        return res;
    }
};
