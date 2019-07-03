/*
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
*/
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> B(A.size()+1,0);
        int res=INT_MAX;
        for(int i=0;i<A.size();i++) B[i+1]=B[i]+A[i];
        deque<int> d;
        for(int i=0;i<B.size();i++){
            while(d.size()>0 && B[i]-B[d.front()]>=K){
                res=min(res,i-d.front());
                d.pop_front();
            }
            while(d.size()>0 && B[i]<=B[d.back()]) d.pop_back();
            d.push_back(i);
        }
        return res==INT_MAX?-1:res;
    }
};
