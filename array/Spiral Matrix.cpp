/*
https://leetcode.com/problems/spiral-matrix/

*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n=matrix.size();
        if(n==0) return res;
        int m=matrix[0].size();
        int rb=0,re=n-1,cb=0,ce=m-1;
        while(rb<=re&&cb<=ce){
            for(int i=cb;i<=ce;i++)
                res.push_back(matrix[rb][i]);
            rb++;
            for(int i=rb;i<=re;i++)
                res.push_back(matrix[i][ce]);
            ce--;
            if(rb<=re){
            for(int i=ce;i>=cb;i--)
                res.push_back(matrix[re][i]);
            }
            re--;
            if(cb<=ce){
            for(int i=re;i>=rb;i--)
                res.push_back(matrix[i][cb]);
            }
            cb++;
        }
        return res;
    }
};
