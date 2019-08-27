/*
https://leetcode.com/problems/couples-holding-hands/

*/
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size(),res=0;
        vector<int> pos(n);
        for(int i=0;i<n;i++) pos[row[i]]=i;
        for(int i=0;i<n;i+=2){
            int pair=row[i]%2==0?(row[i]+1):row[i]-1;
            if(row[i+1]!=pair){
                row[pos[pair]]=row[i+1];
                pos[row[i+1]]=pos[pair];
                res++;
            }
        }
        return res;
    }
};
