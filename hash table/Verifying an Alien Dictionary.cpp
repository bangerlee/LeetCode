/*
https://leetcode.com/problems/verifying-an-alien-dictionary/

*/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        for(int i=0;i<order.size();i++)
            m[order[i]]=i;
        for(int i=0;i<21;i++){
            bool f=true;
            for(int j=0;j<words.size()-1;j++){
                if(words[j].length()>=i+1&&words[j+1].length()<i+1) return false;
                if(words[j].length()>=i+1&&words[j+1].length()>=i+1){
                    if(m[words[j][i]]>m[words[j+1][i]]) return false;
                    if(m[words[j][i]]==m[words[j+1][i]]) f=false;
                }
            }
            if(f) return true;
        }
        return true;
    }
};
