/*
https://leetcode.com/problems/valid-word-abbreviation/

*/
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int res=0,i=0;
        if(abbr.length()>word.length()) return false;
        while(i<abbr.length()&&res<word.length()){
            if(!isdigit(abbr[i])){
                if(abbr[i]!=word[res]) break;
                else i++,res++;
            }
            int tmp=0;
            if(abbr[i]=='0') break;
            while(isdigit(abbr[i]))
                tmp=tmp*10+(abbr[i++]-'0');
            res+=tmp;
        }
        return res==word.length()&&i==abbr.length();
    }
};
