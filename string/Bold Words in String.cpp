/*
https://leetcode.com/problems/bold-words-in-string/

*/
class Solution {
private:
    void mark(string& S,string word,vector<bool>& v){
        for(int i=0;i<=S.length()-word.length();i++){
            if(S.substr(i,word.length())==word){
                for(int j=i;j<i+word.length();j++) v[j]=true;
            }
        }
    }
public:
    string boldWords(vector<string>& words, string S) {
        vector<bool> v(S.length(),false);
        for(auto word:words) mark(S,word,v);
        string res="";
        for(int i=0;i<v.size();i++){
            if(v[i]&&(i==0||!v[i-1])) res+="<b>";
            res+=string(1,S[i]);
            if(v[i]&&(i==S.length()-1||!v[i+1])) res+="</b>";
        }
        return res;
    }
};
