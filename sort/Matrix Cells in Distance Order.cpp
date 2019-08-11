/*
https://leetcode.com/problems/matrix-cells-in-distance-order/

*/
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<int> counter(R+C+1,0);
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                int dist=abs(r-r0)+abs(c-c0);
                counter[dist+1]++;
            }
        }
        for(int i=1;i<counter.size();i++) counter[i]+=counter[i-1];
        vector<vector<int>> res(R*C);
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                int dist=abs(r-r0)+abs(c-c0);
                res[counter[dist]]={r,c};
                counter[dist]++;
            }
        }
        return res;
    }
};
