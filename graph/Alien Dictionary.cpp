/*
https://leetcode.com/problems/alien-dictionary/

*/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,set<char>> graph;
        unordered_map<char,int> indegree;
        for(auto& w:words){
            for(auto& c:w) indegree[c]=0;
        }
        for(int i=0;i<words.size()-1;i++){
            string cur=words[i],next=words[i+1];
            int minlen=min(cur.size(),next.size());
            for(int j=0;j<minlen;j++){
                char curc=words[i][j],nextc=words[i+1][j];
                if(curc!=nextc){
                    if(!graph[curc].count(nextc)){
                        graph[curc].insert(nextc);
                        indegree[nextc]++;
                    }
                    break;
                }
            }
        }
    }
        string res="";
        queue<char> q;
        for(auto& it:indegree)
            if(it.second==0) q.push(it.first);
        while(!q.empty()){
            char cur=q.front();q.pop();
            res+=string(1,cur);
            for(auto next:graph[cur])
                if(--indegree[next]==0) q.push(next);
            if(res.length()==indegree.size()) return res;
            return "";
    }
};
