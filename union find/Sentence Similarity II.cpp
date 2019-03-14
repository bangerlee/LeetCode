/*
https://leetcode.com/problems/sentence-similarity-ii/

*/
class Solution {
private:
    string find(unordered_map<string,string>& m,string s){
        if(m.count(s)==0) return s;
        return m[s]==s?s:find(m,m[s]);
    }
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        unordered_map<string,string> m;
        if(words1.size()!=words2.size()) return false;
        for(auto pair:pairs){
            string parent1=find(m,pair.first);
            string parent2=find(m,pair.second);
            if(parent1!=parent2) m[parent1]=parent2;
        }
        for(int i=0;i<words1.size();i++){
            if(words1[i]==words2[i]) continue;
            if(find(m,words1[i])!=find(m,words2[i])) return false;
        }
        return true;
    }
};
