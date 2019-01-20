/*
https://leetcode.com/problems/find-all-anagrams-in-a-string/

*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        map<char,int> m;
        map<char,int> mt;
        vector<int> res;
        if(s.length()<p.length())
            return res;
        for(int i=0;i<p.length();i++){
            if(m.find(p[i])==m.end())
                m[p[i]]=1;
            else
                m[p[i]]++;
        }
        int i=0;
        for(;i<p.length();i++){
            if(mt.find(s[i])==mt.end())
                mt[s[i]]=1;
            else
                mt[s[i]]++;
        }
        if(mt==m) res.push_back(0);
        for(;i<s.length();i++){
            if(mt.find(s[i])==mt.end())
                mt[s[i]]=1;
            else
                mt[s[i]]++;
            mt[s[i-p.length()]]--;
            if(mt[s[i-p.length()]]==0)
                mt.erase(s[i-p.length()]);
            if(mt==m) res.push_back(i-p.length()+1);
        }
        return res;
    }
};
