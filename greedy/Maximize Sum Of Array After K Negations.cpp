/*
https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

*/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x:A) pq.push(x);
        while(K-->0){
            int tmp=pq.top();pq.pop();
            pq.push(-tmp);
        }
        int res=0;
        while(!pq.empty()){
            res+=pq.top();pq.pop();
        }
        return res;
    }
};
