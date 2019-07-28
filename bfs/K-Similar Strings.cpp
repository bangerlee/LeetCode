/*
https://leetcode.com/problems/k-similar-strings/

*/
class Solution {
public:
    int kSimilarity(string A, string B) {
        if(A==B) return 0;
        unordered_set<string> vis;
        queue<string> q;
        q.push(A);
        vis.insert(A);
        int res=0;
        while(!q.empty()){
            res++;
            for(int sz=q.size();sz>0;sz--){
                string s=q.front();q.pop();
                int i=0;
                while(s[i]==B[i]) i++;
                for(int j=i+1;j<s.length();j++){
                    if(s[j]==B[j]||s[i]!=B[j]) continue;
                    string tmp=s;
                    swap(tmp[i],tmp[j]);
                    if(tmp==B) return res;
                    if(!vis.count(tmp)){
                        vis.insert(tmp);
                        q.push(tmp);
                    }
                }
            }
        }
        return res;
    }
};
