/*
https://leetcode.com/problems/sort-array-by-parity-ii/

*/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i=0,j=A.size()-1;
        while(i<j){
            while((i%2==0&&A[i]%2==0)||(i%2==1&&A[i]%2==1)) i++;
            while((j%2==0&&A[j]%2==0)||(j%2==1&&A[j]%2==1)) j--;
            int tmp=j;
            while(tmp>i&&A[tmp]%2!=i%2) tmp--;
            if(tmp>i){
                swap(A[i],A[tmp]);
                i++;
            }
        }
        return A;
    }
};
