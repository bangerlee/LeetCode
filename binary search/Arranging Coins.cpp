/*
https://leetcode.com/problems/arranging-coins/

Runtime: 40 ms
*/
class Solution {
public:
    int arrangeCoins(int n) {
        long ln=n;  //注意用long
        long i=0,j=ln/2+1,mid;
        while(i<=j){
            mid=i+(j-i)/2;
            if((mid+1)*mid<=ln*2) i=mid+1;
            else j=mid-1;
        }
        return i-1;
    }
};
