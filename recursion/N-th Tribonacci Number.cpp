/*
https://leetcode.com/problems/n-th-tribonacci-number/

*/
class Solution {
private:
    vector<int> nums={0,1,1};
    int maxN=2;
public:
    int tribonacci(int n) {
        if(n<=maxN) return nums[n%3];
        nums[n%3]=tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
        maxN=n;
        return nums[n%3];
    }
};
