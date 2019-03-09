/*
https://leetcode.com/problems/candy-crush/

*/
class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int M=board.size(),N=board[0].size();
        bool flag=true;
        while(flag){
            flag=false;
            for(int i=0;i<M;i++){
                for(int j=0;j<N;j++){
                    int val=abs(board[i][j]);
                    if(val==0) continue;
                    if(j<N-2&&abs(board[i][j+1])==val&&abs(board[i][j+2])==val){
                        flag=true;
                        int ind=j;
                        while(ind<N&&abs(board[i][ind])==val) board[i][ind++]=-val;
                    }
                    if(i<M-2&&abs(board[i+1][j])==val&&abs(board[i+2][j])==val){
                        flag=true;
                        int ind=i;
                        while(ind<M&&abs(board[ind][j])==val) board[ind++][j]=-val;
                    }
                }
            }
            if(flag){
                for(int j=0;j<N;j++){
                    int end=M-1;
                    for(int i=M-1;i>=0;i--){
                        if(board[i][j]>0) board[end--][j]=board[i][j];
                    }
                    for(int k=end;k>=0;k--) board[k][j]=0;
                }
            }
        }
        return board;
    }
};
