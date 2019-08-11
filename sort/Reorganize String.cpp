/*
https://leetcode.com/problems/reorganize-string/

*/
class Solution {
private:
    struct compare{
        bool operator()(const pair<char,int> a,const pair<char,int> b){
            return b.second>a.second;
        }  
    };
public:
    string reorganizeString(string S) {
        unordered_map<char,int> m;
        for(auto& c:S) m[c]++;
        string res="";
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare> pq;
        for(auto& k:m) pq.push(k);
        queue<pair<char,int>> q;
        while(!pq.empty()){
            pair<char,int> tmp=pq.top();pq.pop();
            res+=string(1,tmp.first);
            tmp.second--;
            q.push(tmp);
            if(q.size()>=2){
                pair<char,int> p=q.front();q.pop();
                if(p.second>0) pq.push(p);
            }
        }
        return res.length()==S.length()?res:"";
    }
};
