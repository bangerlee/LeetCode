/*
https://leetcode.com/problems/lonely-pixel-i/

*/
class Solution {
private:
    bool judge(vector<vector<char>>& p,int i,int j){
        for(int k=0;k<p[0].size();k++){
            if(k==j) continue;
            if(p[i][k]=='B'||p[i][k]=='C'){
                p[i][k]='C';
                p[i][j]='C';
                return false;
            }
        }
        for(int k=0;k<p.size();k++){
            if(k==i) continue;
            if(p[k][j]=='B'||p[k][j]=='C'){
                p[k][j]='C';
                p[i][j]='C';
                return false;
            }
        }
        return true;
    }
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int res=0;
        for(int i=0;i<picture.size();i++){
            for(int j=0;j<picture[0].size();j++){
                if(picture[i][j]=='B'&&judge(picture,i,j)) ++res;
            }
        }
        return res;
    }
};
