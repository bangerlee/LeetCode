/*
https://leetcode.com/problems/remove-invalid-parentheses/

*/
class Solution {
private:
    void helper(string s,vector<string>& res,int istart,int jstart,char open,char close){
        int numopen=0,numclose=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==open) numopen++;
            else if(s[i]==close) numclose++;
            if(numclose>numopen){
                for(int j=jstart;j<=i;j++){
                    if(s[j]==close&&(j==jstart||s[j-1]!=s[j]))
                        helper(s.substr(0,j)+s.substr(j+1),res,i,j,open,close);
                }
                return;
            }
        }
        reverse(s.begin(),s.end());
        if(open=='(') helper(s,res,0,0,close,open);
        else res.push_back(s);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        helper(s,res,0,0,'(',')');
        return res;
    }
};
