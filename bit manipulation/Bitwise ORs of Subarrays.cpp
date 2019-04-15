/*
https://leetcode.com/problems/bitwise-ors-of-subarrays/

*/
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> cur,cur2,res;
        for(auto x:A){
            cur2={x};
            for(auto p:cur) cur2.insert(p|x);
            cur=cur2;
            for(auto p:cur) res.insert(p);
        }
        return res.size();
    }
};
