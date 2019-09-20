/*
https://leetcode.com/problems/number-of-enclaves/

*/
class Solution {
private:
    void dfs(vector<vector<int>>& A,int i,int j){
        if(i<0||j<0||i==A.size()||j==A[i].size()||A[i][j]!=1) return;
        A[i][j]=0;
        dfs(A,i+1,j);
        dfs(A,i-1,j);
        dfs(A,i,j+1);
        dfs(A,i,j-1);
    }
public:
    int numEnclaves(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++)
            for(int j=0;j<A[0].size();j++)
                if(i*j==0||i==A.size()-1||j==A[i].size()-1) dfs(A,i,j);
        return accumulate(A.begin(),A.end(),0,[](int s,vector<int> &r){
            return s+accumulate(r.begin(),r.end(),0); 
        });
    }
};
