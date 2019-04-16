/*
https://leetcode.com/problems/alien-dictionary/

*/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res="";
        if(words.size()==0) return res;
        unordered_map<char,set<char>> graph;
        unordered_map<char,int> indegree;
        for(auto word:words)
            for(auto c:word) indegree[c]=0;
        
        for(int i=0;i<words.size()-1;i++){
            string curw=words[i];
            string nextw=words[i+1];
            int minLen=min(curw.length(),nextw.length());
            
            for(int j=0;j<minLen;j++){
                char curc=curw[j];
                char nextc=nextw[j];
                if(curc!=nextc){
                    if(!graph[curc].count(nextc)){
                        graph[curc].insert(nextc);
                        indegree[nextc]++;
                    }
                    break;
                }
            }
        }
        queue<char> q;
        for(auto p:indegree){
            if(p.second==0) q.push(p.first);
        }
        while(!q.empty()){
            char curChar=q.front();
            q.pop();
            res+=string(1,curChar);
            if(graph.count(curChar)){
                for(auto nextChar:graph[curChar])
                    if(--indegree[nextChar]==0)
                        q.push(nextChar);
            }
        }
        if(res.length()!=indegree.size()) return "";
        return res;
    }
};
