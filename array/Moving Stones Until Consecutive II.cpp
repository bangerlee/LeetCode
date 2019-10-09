/*
https://leetcode.com/problems/moving-stones-until-consecutive-ii/

*/
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int i=0,n=stones.size(),low=n;
        int high=max(stones[n-1]-n+2-stones[1],stones[n-2]-stones[0]-n+2);
        for(int j=0;j<n;j++){
            while(stones[j]-stones[i]>=n) ++i;
            if(j-i+1==n-1&&stones[j]-stones[i]==n-2)
                low=min(low,2);
            else
                low=min(low,n-(j-i+1));
        }
        return {low,high};
    }
};
