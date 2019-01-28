/*
https://leetcode.com/problems/maximize-distance-to-closest-person/

*/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res=0,i=0,j=0;
        for(;j<seats.size();j++)
            if(seats[j]==1){
                if(i==0) res=max(res,j-i);
                else res=max(res,(j-i+1)/2);
                i=j+1;
            }
        int tmp=seats.size()-i;
        res=max(res,tmp);
        return res;
    }
};
