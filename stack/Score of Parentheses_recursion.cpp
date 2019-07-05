/*
https://leetcode.com/problems/score-of-parentheses/
*/
class Solution {
private:
    int i=0;
public:
    int scoreOfParentheses(string S) {
        int res=0;
        while(i<S.length()){
            char c=S[i++];
            if(c=='('){
                if(S[i]==')'){
                    res+=1;
                    i++;
                }else res+=2*scoreOfParentheses(S);
            }else return res;
        }
        return res;
    }
};
