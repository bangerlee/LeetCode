/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold=-prices[0],empty=0;
        for(int i=1;i<prices.size();i++){
            hold=max(hold,empty-prices[i]);
            empty=max(empty,hold+prices[i]-fee);
        }
        return empty;
    }
};
