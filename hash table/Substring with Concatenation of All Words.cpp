/*
https://leetcode.com/problems/substring-with-concatenation-of-all-words/

*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> m;
        vector<int> res;
        for(string word:words) m[word]++;
        int n=s.length(), num=words.size();
        if(n==0||num==0) return res;
        int len=words[0].length();
        for(int i=0;i<n-num*len+1;i++){
            unordered_map<string,int> seen;
            int j=0;
            for(;j<num;j++){
                string word=s.substr(i+j*len,len);
                if(m.count(word)){
                    seen[word]++;
                    if(seen[word]>m[word]) break;
                }
                else break;
            }
            if(j==num) res.push_back(i);
        }
        return res;
    }
};
