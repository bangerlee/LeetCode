/*
https://leetcode.com/problems/koko-eating-bananas/

Runtime: 64 ms
*/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo=1,hi=*max_element(piles.begin(),piles.end());
        while(lo<hi){
            int hour=0,mid=(lo+hi)/2;
            for(int p:piles)
                hour+=(p+mid-1)/mid;
            if(hour>H) lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
};
