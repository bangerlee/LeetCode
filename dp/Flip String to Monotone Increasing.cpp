/*
https://leetcode.com/problems/flip-string-to-monotone-increasing/

*/
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        vector<int> f0(S.length()+1);
        vector<int> f1(S.length()+1);
        int res=INT_MAX;
        for(int i=1,j=S.length()-1;j>=0;j--,i++){
            f0[i]+=f0[i-1]+(S[i-1]=='0'?0:1);
            f1[j]+=f1[j+1]+(S[j]=='1'?0:1);
        }
        for(int i=0;i<=S.length();i++) res=min(res,f0[i]+f1[i]);
        return res;
    }
};
