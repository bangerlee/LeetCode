/*
https://leetcode.com/problems/word-break/

*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> myset(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.length()+1,false);
        dp[0]=true;
        for(int i=0;i<=s.length();i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&myset.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
