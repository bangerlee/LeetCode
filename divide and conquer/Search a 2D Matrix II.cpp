/*
https://leetcode.com/problems/search-a-2d-matrix-ii/

*/
class Solution {
private:
    bool searchRect(vector<vector<int>>& matrix,int target,int top,int left,int bottom,int right){
        if(top>bottom||left>right) return false;
        int x=(top+bottom)/2,y=(left+right)/2,mid=matrix[x][y];
        if(mid>target)
            return searchRect(matrix,target,top,left,x-1,right) ||
            searchRect(matrix,target,x,left,bottom,y-1);
        else if(mid<target){
            return searchRect(matrix,target,x+1,left,bottom,right) ||
                searchRect(matrix,target,top,y+1,x,right);
        }
        else return true;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return 0;
        return searchRect(matrix,target,0,0,matrix.size()-1,matrix[0].size()-1);
    }
};
