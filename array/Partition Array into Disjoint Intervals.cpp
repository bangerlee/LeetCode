/*
https://leetcode.com/problems/partition-array-into-disjoint-intervals/

*/
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int localmax=A[0],m=localmax,res=0;
        for(int i=1;i<A.size();i++){
            if(localmax>A[i]){
                res=i;
                localmax=m;
            }
            else m=max(m,A[i]);
        }
        return res+1;
    }
};
