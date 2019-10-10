/*
https://leetcode.com/problems/transpose-matrix/

*/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.size()==0)
            return A;
        vector<vector<int>> res(A[0].size());
        for(int c=0;c<A[0].size();c++)
            for(int r=0;r<A.size();r++)
                res[c].push_back(A[r][c]);
        return res;
    }
};
