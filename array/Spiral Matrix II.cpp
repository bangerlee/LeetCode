/*
https://leetcode.com/problems/spiral-matrix-ii/

*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int i=0,k=1;
        while(k<=n*n){
            int j=i;
            while(j<n-i)
                res[i][j++]=k++;
            j=i+1;
            while(j<n-i)
                res[j++][n-i-1]=k++;
            j=n-i-2;
            while(j>i)
                res[n-i-1][j--]=k++;
            j=n-i-1;
            while(j>i)
                res[j--][i]=k++;
            ++i;
        }
        return res;
    }
};
