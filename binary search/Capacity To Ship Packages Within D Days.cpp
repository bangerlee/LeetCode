/*
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

*/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int lo=0,hi=0;
        for(auto w:weights)
            lo=max(lo,w),hi+=w;
        while(lo<hi){
            int mid=(lo+hi)/2,d=1,cur=0;
            for(int i=0;i<weights.size()&&d<=D;cur+=weights[i++])
                if(cur+weights[i]>mid) cur=0,d++;
            if(d>D) lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
};
