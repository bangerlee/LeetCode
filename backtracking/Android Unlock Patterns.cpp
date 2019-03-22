/*
https://leetcode.com/problems/android-unlock-patterns/

*/
class Solution {
private:
    int helper(vector<bool>& visited,vector<vector<int>>& skip,int cur,int remain){
        if(remain<0) return 0;
        if(remain==0) return 1;
        visited[cur]=true;
        int res=0;
        for(int i=1;i<=9;i++){
            if(!visited[i]&&(skip[cur][i]==0||visited[skip[cur][i]]))
                res+=helper(visited,skip,i,remain-1);
        }
        visited[cur]=false;
        return res;
    }
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10,vector<int>(10));
        skip[1][3]=skip[3][1]=2;
        skip[3][9]=skip[9][3]=6;
        skip[1][7]=skip[7][1]=4;
        skip[7][9]=skip[9][7]=8;
        skip[4][6]=skip[6][4]=skip[1][9]=skip[9][1]=skip[2][8]=skip[8][2]=skip[3][7]=skip[7][3]=5;
        vector<bool> visited(10,false);
        int res=0;
        for(int i=m;i<=n;i++){
            res+=helper(visited,skip,1,i-1)*4;
            res+=helper(visited,skip,2,i-1)*4;
            res+=helper(visited,skip,5,i-1);
        }
        return res;
    }
};
