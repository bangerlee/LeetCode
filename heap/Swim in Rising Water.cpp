/*
https://leetcode.com/problems/swim-in-rising-water/

*/
class Solution {
public:
    struct T{
        int t,x,y;
        T(int a, int b, int c): t(a), x(b), y(c){}
        bool operator< (const T &d) const {return t>d.t;}
    };
    int swimInWater(vector<vector<int>>& grid) {
        int N=grid.size(),res=0;
        priority_queue<T> pq;
        pq.push(T(grid[0][0], 0, 0));
        vector<vector<bool>> seen(N, vector<bool>(N,false));
        seen[0][0]=true;
        static int dir[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(true){
            auto p=pq.top(); pq.pop();
            res=max(res, p.t);
            if(p.x==N-1 && p.y==N-1) return res;
            for(auto& d:dir){
                int i=p.x+d[0], j=p.y+d[1];
                if(i>=0 && i<N && j>=0 && j<N && !seen[i][j]){
                    seen[i][j]=true;
                    pq.push(T(grid[i][j], i, j));
                }
            }
        }
    }
};
