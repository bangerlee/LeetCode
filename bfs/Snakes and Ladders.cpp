/*
https://leetcode.com/problems/snakes-and-ladders/

*/
class Solution {
private:
    vector<int> calc(int nxt, int n){
        int x=(nxt-1)/n, y=(nxt-1)%n;
        if(x%2==1) y=n-1-y;
        x=n-1-x;
        return {x,y};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(),res=0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int m=q.size();
            for(int i=0;i<m;i++){
                int cur=q.front();q.pop();
                if(cur==n*n) return res;
                for(int i=1;i<=6;i++){
                    int nxt=cur+i;
                    if(nxt>n*n) break;
                    auto v=calc(nxt,n);
                    int nx=v[0], ny=v[1];
                    if(board[nx][ny]!=-1) nxt=board[nx][ny];
                    if(board[nx][ny]!=n*n+1){
                        q.push(nxt);
                        board[nx][ny]=n*n+1;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
