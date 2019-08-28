/*
https://leetcode.com/problems/last-stone-weight/

*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto& k:stones) pq.push(k);
        while(pq.size()>=2){
            int y=pq.top();pq.pop();
            int x=pq.top();pq.pop();
            if(y-x>0) pq.push(y-x);
        }
        return pq.size()==0?0:pq.top();
    }
};
