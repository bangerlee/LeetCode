/*
https://leetcode.com/problems/friend-circles/

*/

class Solution {
private:
    void dfs(vector<vector<int>>& M,vector<bool>& visited,int k){
        for(int i=0;i<visited.size();i++){
            if(M[k][i]==1&&!visited[i]){
                visited[i]=true;
                dfs(M,visited,i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size(),false);
        int res=0;
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                dfs(M,visited,i);
                res++;
            }
        }
        return res;
    }
};
