/*
https://leetcode.com/problems/fair-candy-swap/

*/
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int dif = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) / 2;
        unordered_set<int> S(A.begin(), A.end());
        for (int b: B)
            if (S.count(b + dif))
                return {b + dif, b};
        return {1,0};
    }
};
