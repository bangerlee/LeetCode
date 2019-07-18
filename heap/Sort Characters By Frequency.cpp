/*
https://leetcode.com/problems/sort-characters-by-frequency/
*/
class Solution {
private:
    struct compare{
        bool operator()(const pair<char,int> a,const pair<char,int> b){
            return b.second>a.second;
        }  
    };
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        string res="";
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare> pq;
        for(auto& c:s) m[c]++;
        for(auto& k:m) pq.push(k);
        while(!pq.empty()){
            pair<char,int> cur=pq.top();pq.pop();
            res+=string(cur.second,cur.first);
        }
        return res;
    }
};
