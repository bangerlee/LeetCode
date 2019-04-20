/*
https://leetcode.com/problems/friend-circles/

*/
class Solution {
private:
    void uniFind(vector<int>& v,int i,int j){
        while(v[i]!=i) i=v[i];
        while(v[j]!=j) j=v[j];
        if(v[i]!=v[j]) v[j]=i;
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int m=M.size(),cnt=0;
        vector<int> v(m);
        for(int i=0;i<m;i++) v[i]=i;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(M[i][j]==1) uniFind(v,i,j);
            }
        }
        for(int i=0;i<m;i++)
            if(i==v[i]) cnt++;
        return cnt;
    }
};
