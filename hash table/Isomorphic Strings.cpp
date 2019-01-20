/*
https://leetcode.com/problems/isomorphic-strings/

*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> m;
        unordered_map<char,int> mt;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int>::iterator it=m.find(s[i]);
            unordered_map<char,int>::iterator itt=mt.find(t[i]);
            if((it==m.end() && itt!=mt.end()) || (it!=m.end() && itt==mt.end()))
                return false;
            else if(it==m.end()&&itt==mt.end()){
                m[s[i]]=i;
                mt[t[i]]=i;
            }
            else{
                if(it->second!=itt->second)
                    return false;
                m[s[i]]=i;
                mt[t[i]]=i;
            }
        }
        return true;
    }
};
