/*
https://leetcode.com/problems/push-dominoes/

*/
class Solution {
public:
    string pushDominoes(string dominoes) {
        string d='L'+dominoes+'R',res="";
        for(int i=0,j=1;j<d.length();j++){
            if(d[j]=='.') continue;
            int mid=j-i-1;
            if(i>0) res+=d[i];
            if(d[i]==d[j]) res+=string(mid,d[i]);
            else if(d[i]=='L'&&d[j]=='R') res+=string(mid,'.');
            else res+=string(mid/2,'R')+string(mid%2,'.')+string(mid/2,'L');
            i=j;
        }
        return res;
    }
};
