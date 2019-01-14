/*
https://leetcode.com/problems/divide-two-integers/

Runtime: 20 ms
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
        int res=0,a,b;
        a=abs(dividend),b=abs(divisor);
        for(int i=31;i>=0;i--){
            if((signed)(unsigned(a)>>i)-b>=0)
                res+=1<<i,a-=b<<i;
        }
        return (dividend>0)==(divisor>0)?res:-res;
    }
};
