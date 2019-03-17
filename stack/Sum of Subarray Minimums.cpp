/*
https://leetcode.com/problems/sum-of-subarray-minimums/

*/
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        stack<pair<int,int>> pst;
        stack<pair<int,int>> nst;
        vector<int> ple(A.size());
        vector<int> nle(A.size());
        for(int i=0;i<A.size();i++) ple[i]=i+1;
        for(int i=0;i<A.size();i++) nle[i]=A.size()-i;
        for(int i=0;i<A.size();i++){
            while(!pst.empty()&&pst.top().first>A[i]) pst.pop();
            ple[i]=pst.empty()?i+1:i-pst.top().second;
            pst.push({A[i],i});
            
            while(!nst.empty()&&nst.top().first>A[i]){
                auto x=nst.top();nst.pop();
                nle[x.second]=i-x.second;
            }
            nst.push({A[i],i});
        }
        int res=0,mod=1e9+7;
        for(int i=0;i<A.size();i++)
            res=(res+A[i]*ple[i]*nle[i])%mod;
        return res;
    }
};
