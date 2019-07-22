/*
https://leetcode.com/problems/minesweeper/

*/
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m=board.size(),n=board[0].size();
        queue<vector<int>> q;
        q.push(click);
        vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{1,-1},{-1,1}};
        while(!q.empty()){
            vector<int> cell=q.front();q.pop();
            int row=cell[0], col=cell[1];
            if(board[row][col]=='M'){
                board[row][col]='X';
                continue;
            }
            int count=0;
            for(int i=0;i<dirs.size();i++){
                int x=row+dirs[i][0], y=col+dirs[i][1];
                if(x<0||x>=m||y<0||y>=n) continue;
                if(board[x][y]=='M' || board[x][y]=='X') count++;
            }
            if(count>0) board[row][col]=(char)(count+'0');
            else{
                board[row][col]='B';
                for(int i=0;i<dirs.size();i++){
                    int x=row+dirs[i][0], y=col+dirs[i][1];
                    if(x<0||x>=m||y<0||y>=n) continue;
                    if(board[x][y]=='E'){
                        q.push({x,y});
                        board[x][y]='B';
                    }
                }
            }
        }
        return board;
    }
};
