/*
https://leetcode.com/problems/search-a-2d-matrix/

Runtime: 12 ms
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int c=matrix[0].size();
        int i=0,j=matrix.size()*c-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            int row=mid/c;
            int col=mid%c;
            if(matrix[row][col]==target) return true;
            if(matrix[row][col]>target) j=mid-1;
            else i=mid+1;
        }
        return false;
    }
};
