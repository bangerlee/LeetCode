/*
https://leetcode.com/problems/4sum-ii/

Runtime: 304 ms
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> m;
        int res=0;
        for(int p:A)
            for(int q:B)
                m[p+q]++;
        for(int i:C)
            for(int j:D)
                res+=m[-i-j];
        return res;
    }
};
