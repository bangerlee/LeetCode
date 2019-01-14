/*
https://leetcode.com/problems/search-a-2d-matrix-ii/

Runtime: 56 ms
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j;
        if(matrix.size()==0) return false;
        if(matrix[0].size()==0) return false;
        j=matrix[0].size()-1;
        while(i<matrix.size()&&j>=0){
            if(matrix[i][j]==target) return true;
            if(matrix[i][j]>target) j--;
            else i++;
        }
        return false;
    }
};
