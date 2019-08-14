/*
https://leetcode.com/problems/backspace-string-compare/

*/
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i=S.length()-1,j=T.length()-1;
        while(1){
            for(int back=0;i>=0&&(back||S[i]=='#');i--)
                back+=S[i]=='#'?1:-1;
            for(int back=0;j>=0&&(back||T[j]=='#');j--)
                back+=T[j]=='#'?1:-1;
            if(i>=0&&j>=0&&S[i]==T[j])
                i--,j--;
            else return i==-1 && j==-1;
        }
    }
};
