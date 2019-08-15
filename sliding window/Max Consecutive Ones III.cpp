/*
https://leetcode.com/problems/max-consecutive-ones-iii/

*/
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int begin=0,end=0,res=0,zerocnt=0;
        while(end<A.size()){
            if(A[end++]==0) zerocnt++;
            while(zerocnt>K){
                if(A[begin++]==0) zerocnt--;
            }
            res=max(res,end-begin);
        }
        return res;
    }
};
