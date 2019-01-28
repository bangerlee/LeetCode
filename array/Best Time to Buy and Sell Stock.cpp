/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0,minp=INT_MAX;
        for(int x:prices){
            minp=min(minp,x);
            maxp=max(maxp,x-minp);
        }
        return maxp;
    }
};
