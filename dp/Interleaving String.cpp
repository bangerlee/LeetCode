/*
https://leetcode.com/problems/interleaving-string/

*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        vector<vector<bool>> v(s1.length()+1,vector<bool>(s2.length()+1,false));
        
        for(int i=0;i<=s1.length();i++){
            for(int j=0;j<=s2.length();j++){
                if(i==0&&j==0) v[i][j]=true;
                else if(i==0)
                    v[i][j]=(v[i][j-1]&&(s2[j-1]==s3[i+j-1]));
                else if(j==0)
                    v[i][j]=(v[i-1][j]&&(s1[i-1]==s3[i+j-1]));
                else
                    v[i][j]=(v[i-1][j]&&s1[i-1]==s3[i+j-1])||(v[i][j-1]&&s2[j-1]==s3[i+j-1]);
            }
        }
        return v[s1.length()][s2.length()];
    }
};
