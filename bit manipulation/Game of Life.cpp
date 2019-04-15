/*
https://leetcode.com/problems/game-of-life/

*/
class Solution {
private:
    int livesCount(vector<vector<int>>& board,int i,int j,int m,int n){
        int lives=0;
        for(int k=max(i-1,0);k<=min(i+1,m-1);k++)
            for(int l=max(j-1,0);l<=min(j+1,n-1);l++)
                lives+=board[k][l]&1;
        lives-=board[i][j]&1;
        return lives;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=livesCount(board,i,j,m,n);
                if(board[i][j]==1&&count>=2&&count<=3) board[i][j]=3;
                if(board[i][j]==0&&count==3) board[i][j]=2;
            }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                board[i][j]>>=1;
    }
};
