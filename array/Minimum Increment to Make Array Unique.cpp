/*
https://leetcode.com/problems/minimum-increment-to-make-array-unique/

Sort the array.
Compared with previous number,
the current number need to be at least prev + 1.
Time Complexity: O(NlogN)

*/
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());
        int res=0,need=0;
        for(int x:A){
            res+=max(need-x,0);
            need=max(need,x)+1;
        }
        return res;
    }
};
