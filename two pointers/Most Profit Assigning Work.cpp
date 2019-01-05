/*
https://leetcode.com/problems/most-profit-assigning-work/

Runtime: 92 ms
*/
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int res=0,tmp=0,j=0;
        vector<pair<int,int>> m;
        for(int i=0;i<difficulty.size();i++)
            m.push_back(make_pair(difficulty[i],profit[i]));
        sort(m.begin(),m.end());
        sort(worker.begin(),worker.end());
        for(int w:worker){
            while(j<m.size()&&w>=m[j].first) 
                tmp=max(tmp,m[j++].second);
            res+=tmp;
        }
        return res;
    }
};
