/*
https://leetcode.com/problems/distant-barcodes/

*/
class Solution {
private:
    struct compare{
        bool operator()(const pair<int,int> a,const pair<int,int> b){
            return b.second > a.second;
        }  
    };
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> m;
        for(auto& k:barcodes) m[k]++;
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(auto& p:m) pq.push(p);
        queue<pair<int,int>> q;
        while(!pq.empty()){
            pair<int,int> cur=pq.top();pq.pop();
            res.push_back(cur.first);
            cur.second--;
            q.push(cur);
            if(q.size()>=2){
                pair<int,int> front=q.front();q.pop();
                if(front.second>0) pq.push(front);
            }
        }
        return res;
    }
};
