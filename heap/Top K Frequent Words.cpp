/*
https://leetcode.com/problems/top-k-frequent-words/
*/
class Solution {
private:
    struct compare{
        bool operator()(const pair<int,string> a,const pair<int,string> b){
            if(b.first==a.first) return a.second>b.second;
            return b.first>a.first;
        }  
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string,int> m;
        for(auto& s:words) m[s]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq;
        for(auto& k:m) pq.push({k.second,k.first});
        for(int i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
