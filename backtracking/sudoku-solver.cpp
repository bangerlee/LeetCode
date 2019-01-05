/*
https://leetcode.com/problems/sudoku-solver/

Runtime: 8 ms
*/

class Solution {
private:
    bool notinrow(vector<char>& cr,char t){
        for(int m=0;m<cr.size();m++){
            if(t==cr[m]) return false;
        }
        return true;
    }
    bool notincol(vector<vector<char>>& board,int j,char t){
        for(int m=0;m<board.size();m++){
            if(t==board[m][j]) return false;
        }
        return true;
    }
    bool notinmm(vector<vector<char>>& board,int i,int j,char t){
        for(int m=i/3*3;m<i/3*3+3;m++){
            for(int n=j/3*3;n<j/3*3+3;n++){
                if(t==board[m][n]) return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<char>>& board,int count){
        if(count>=81) return true;
        int i=count/9;
        int j=count%9;
        if(board[i][j]!='.'){
            return dfs(board,count+1);
        }
        else{
            for(char k='1';k<='9';k++){
                if(notinrow(board[i],k)&&notincol(board,j,k)&&notinmm(board,i,j,k)){
                        board[i][j]=k;
                        if(dfs(board,count+1)) return true;
                    board[i][j]='.';
                }
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int count=0;
        dfs(board,count);
    }
};
