/*
https://leetcode.com/problems/rearrange-string-k-distance-apart/

*/
class Solution {
private:
    struct compare{
        bool operator()(const vector<int> a,const vector<int> b){
            return b[1]>a[1];
        }  
    };
public:
    string rearrangeString(string s, int k) {
        if(k==0) return s;
        vector<int> freq(26,0);
        string res="";
        for(char c:s) freq[c-'a']++;
        priority_queue<vector<int>,vector<vector<int>>,compare> pq;
        for(int i=0;i<26;i++)
            if(freq[i]>0) pq.push({i,freq[i]});
        queue<vector<int>> q;
        while(!pq.empty()){
            vector<int> cur=pq.top();pq.pop();
            res+=string(1,cur[0]+'a');
            cur[1]--;
            q.push(cur);
            if(q.size()>=k){
                vector<int> front=q.front();q.pop();
                if(front[1]>0) pq.push(front);
            }
        }
        return res.length()==s.length()?res:"";
    }
};
