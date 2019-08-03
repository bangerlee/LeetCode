/*
https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

*/
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> m;
        for(vector<int>& x:matrix){
            string s="";
            int first=x[0];
            for(auto i:x){
                if(i==first) s+="1";
                else s+="0";
            }
            m[s]++;
        }
        int res=0;
        for(auto& k:m) res=max(res,k.second);
        return res;
    }
};
