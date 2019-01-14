/*
https://leetcode.com/problems/sqrtx/

Runtime: 12 ms
*/
class Solution {
public:
    int mySqrt(int x) {
        int left=1;
        int right=x;
        if(x==0) return 0;
        while(true){
            int mid=left+(right-left)/2;
            if(mid>x/mid){
                right=mid-1;
            }
            else{
                if(mid+1>x/(mid+1))
                    return mid;
                left=mid+1;
            }
        }
    }
};
