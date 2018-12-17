/*
https://leetcode.com/problems/word-search/

Runtime: 20 ms
*/
class Solution {
private:
    bool backtrack(vector<vector<char>>& board,string& word,int start,int row,int col,int m,int n){
        //if(start==word.length()-1) //return true;
        char c=board[row][col];
        if(c!=word[start]) return false;
        if(start==word.length()-1) return true;
        board[row][col]='*';
        bool res=false;
        if(row>0) res=backtrack(board,word,start+1,row-1,col,m,n);
        if(!res&&col<n-1) res=backtrack(board,word,start+1,row,col+1,m,n);
        if(!res&&row<m-1) res=backtrack(board,word,start+1,row+1,col,m,n);
        if(!res&&col>0) res=backtrack(board,word,start+1,row,col-1,m,n);
        board[row][col]=c;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        if(m==0||word.length()==0) return false;
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(backtrack(board,word,0,i,j,m,n)) return true;
            }
        }
        return false;
    }
};
