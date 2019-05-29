/*
https://leetcode.com/problems/replace-words/

*/
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        if(dict.size()==0) return sentence;
        set<string> dict_set(dict.begin(),dict.end());
        stringstream ss(sentence);
        string word="",res="";
        while(ss>>word){
            string prefix="";
            for(int i=1;i<=word.length();i++){
                prefix=word.substr(0,i);
                if(dict_set.count(prefix)) break;
            }
            res+=" "+prefix;
        }
        return res.substr(1);
    }
};
