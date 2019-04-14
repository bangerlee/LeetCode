/*
https://leetcode.com/problems/repeated-dna-sequences/

*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> words;
        vector<string> res;
        if(s.length()<10) return res;
        unordered_map<int,int> m;
        m['A'-'A']=0;
        m['C'-'A']=1;
        m['G'-'A']=2;
        m['T'-'A']=3;
        for(int i=0;i<s.length()-9;i++){
            int v=0;
            for(int j=i;j<i+10;j++){
                v<<=2;
                v|=m[s[j]-'A'];
            }
            if(words[v]++==1) res.push_back(s.substr(i,10));
        }
        return res;
    }
};
