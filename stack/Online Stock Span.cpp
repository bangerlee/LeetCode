/*
https://leetcode.com/problems/online-stock-span/

Runtime: 192 ms
*/
class StockSpanner {
private:
    stack<pair<int,int>> st;
    int idx=0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,idx++});
            return 1;
        }
        int res;
        while(!st.empty()&&st.top().first<=price)
            st.pop();
        res=st.empty()?idx+1:idx-st.top().second;
        st.push({price,idx++});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
