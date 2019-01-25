/*
https://leetcode.com/problemset/all/?topicSlugs=array

*/
class Solution {
public:
    int fib(int N) {
        if(N<=1) return N;
        int a=0,b=1,sum=0;
        while(N-->1){
            int sum=a+b;
            a=b;
            b=sum;
        }
        return b;
    }
};
