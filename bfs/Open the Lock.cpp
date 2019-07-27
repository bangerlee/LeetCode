/*
https://leetcode.com/problems/open-the-lock/

*/
class Solution {
private:
    vector<string> nbrStrs(string key){
        vector<string> res;
        for(int i=0;i<4;i++){
            string tmp=key;
            tmp[i]=(key[i]-'0'+1)%10+'0';
            res.push_back(tmp);
            tmp[i]=(key[i]-'0'-1+10)%10+'0';
            res.push_back(tmp);
        }
        return res;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dds(deadends.begin(),deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        string init="0000";
        if(dds.count(init)) return -1;
        visited.insert(init);
        q.push(init);
        
        int res=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string t=q.front();q.pop();
                vector<string> nbrs=nbrStrs(t);
                for(auto& s:nbrs){
                    if(s==target) return ++res;
                    if(visited.count(s)) continue;
                    if(!dds.count(s)){
                        q.push(s);
                        visited.insert(s);
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};
