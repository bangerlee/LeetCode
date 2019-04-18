/*
https://leetcode.com/problems/subarrays-with-k-different-integers/

*/
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int begin=0,end=0,cnt=0,prefix=0,res=0;
        vector<int> m(A.size()+1,0);
        while(end<A.size()){
            if(m[A[end++]]++==0) cnt++;
            if(cnt>K){
                --m[A[begin++]];
                --cnt;
                prefix=0;
            }
            while(m[A[begin]]>1) ++prefix,--m[A[begin++]];
            if(cnt==K) res+=prefix+1;
        }
        return res;
    }
};
