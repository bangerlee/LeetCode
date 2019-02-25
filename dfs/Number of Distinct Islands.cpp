/*
https://leetcode.com/problems/number-of-distinct-islands/

*/
class Solution {
private:
    void helper(vector<vector<int>>& grid,int i,int j,string& s,string tmp){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()) return;
        if(grid[i][j]==0) return;
        grid[i][j]=0;
        s+=tmp;
        helper(grid,i-1,j,s,"u");
        helper(grid,i+1,j,s,"d");
        helper(grid,i,j-1,s,"l");
        helper(grid,i,j+1,s,"r");
        s+="b";
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<string> ss;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    string s="";
                    helper(grid,i,j,s,"o");
                    ss.insert(s);
                }
            }
        }
        return ss.size();
    }
};
