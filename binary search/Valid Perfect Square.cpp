/*
https://leetcode.com/problems/valid-perfect-square/

Runtime: 0 ms
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        int x=1,h=num;
        while(x<=h){
            long mid=(h+x)/2;
            if(mid*mid==num) return true;
            if(mid*mid<num) x=mid+1;
            else h=mid-1;
        }
        return false;
    }
};
