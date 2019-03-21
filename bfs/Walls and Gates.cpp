/*
https://leetcode.com/problems/walls-and-gates/

*/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> q;
        for(int i=0;i<rooms.size();i++)
            for(int j=0;j<rooms[i].size();j++)
                if(rooms[i][j]==0) q.push({i,j});
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int row=p.first,col=p.second;
            if(row>0&&rooms[row-1][col]==INT_MAX){
                rooms[row-1][col]=rooms[row][col]+1;
                q.push({row-1,col});
            }
            if(col>0&&rooms[row][col-1]==INT_MAX){
                rooms[row][col-1]=rooms[row][col]+1;
                q.push({row,col-1});
            }
            if(row<rooms.size()-1&&rooms[row+1][col]==INT_MAX){
                rooms[row+1][col]=rooms[row][col]+1;
                q.push({row+1,col});
            }
            if(col<rooms[row].size()-1&&rooms[row][col+1]==INT_MAX){
                rooms[row][col+1]=rooms[row][col]+1;
                q.push({row,col+1});
            }
        }
    }
};
