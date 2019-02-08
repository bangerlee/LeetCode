/*
https://leetcode.com/problems/longest-palindromic-subsequence/

*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> v(s.length(),vector<int>(s.length()));
        for(int i=s.length()-1;i>=0;i--){
            v[i][i]=1;
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j]) v[i][j]=v[i+1][j-1]+2;
                else
                    v[i][j]=max(v[i+1][j],v[i][j-1]);
            }
        }
        return v[0][s.length()-1];
    }
};
