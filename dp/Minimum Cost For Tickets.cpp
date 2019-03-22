/*
https://leetcode.com/problems/minimum-cost-for-tickets/

*/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int cost=0;
        queue<pair<int,int>> qlst7,qlst30;
        for(auto day:days){
            while(!qlst7.empty()&&qlst7.front().first<=day-7) qlst7.pop();
            while(!qlst30.empty()&&qlst30.front().first<=day-30) qlst30.pop();
            qlst7.push({day,costs[1]+cost});
            qlst30.push({day,costs[2]+cost});
            cost=min(min(cost+costs[0],qlst7.front().second),qlst30.front().second);
        }
        return cost;
    }
};
