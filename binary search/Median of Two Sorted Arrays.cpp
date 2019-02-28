/*
https://leetcode.com/problems/median-of-two-sorted-arrays/

*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1=nums1.size(),N2=nums2.size();
        if(N2>N1) return findMedianSortedArrays(nums2,nums1);
        int lo=0,hi=N2*2;
        while(lo<=hi){
            int mid2=(lo+hi)/2;
            int mid1=N1+N2-mid2;
            double L1=(mid1==0)?INT_MIN:nums1[(mid1-1)/2];
            double L2=(mid2==0)?INT_MIN:nums2[(mid2-1)/2];
            double R1=(mid1==N1*2)?INT_MAX:nums1[mid1/2];
            double R2=(mid2==N2*2)?INT_MAX:nums2[mid2/2];
            
            if(L1>R2) lo=mid2+1;
            else if(L2>R1) hi=mid2-1;
            else return (max(L1,L2)+min(R1,R2))/2;
        }
        return -1;
    }
};
