/*
https://leetcode.com/problems/sort-array-by-parity/

*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res(A.size());
        int i=0,k=0,j=A.size()-1;
        for(;k<A.size();k++){
            if(A[k]%2==1) res[j--]=A[k];
            else  res[i++]=A[k];
        }
        return res;
    }
};
