/*
https://leetcode.com/problems/pascals-triangle/

*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for(int i=1;i<=numRows;i++){
            for(int j=1;j<=i;j++){
                res[i-1].push_back(1);
                if(j!=1 && j!=i)
                    res[i-1][j-1]=res[i-2][j-2]+res[i-2][j-1];
            }
        }
        return res;
    }
};
