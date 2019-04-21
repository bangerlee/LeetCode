/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur=0,res=0;
        for(int i=1;i<prices.size();i++){
            cur=max(0,cur+=prices[i]-prices[i-1]);
            res=max(cur,res);
        }
        return res;
    }
};
