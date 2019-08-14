/*
https://leetcode.com/problems/squares-of-a-sorted-array/

*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n=A.size();
        vector<int> res(n,0);
        int i=0,j=n-1;
        for(int p=n-1;p>=0;p--){
            if(abs(A[i])>abs(A[j])){
                res[p]=A[i]*A[i];
                i++;
            }
            else{
                res[p]=A[j]*A[j];
                j--;
            }
        }
        return res;
    }
};
