/*
https://leetcode.com/problems/top-k-frequent-elements/

*/
class Solution {
private:
    struct compare{
        bool operator()(const vector<int> a,const vector<int> b){
            return b[0]>a[0];
        }  
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<vector<int>,vector<vector<int>>,compare> pq;
        unordered_map<int,int> m;
        for(auto& x:nums) m[x]++;
        for(auto& k:m) pq.push({k.second,k.first});
        for(int i=0;i<k;i++){
            res.push_back(pq.top()[1]);
            pq.pop();
        }
        return res;
    }
};
