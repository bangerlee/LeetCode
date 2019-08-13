/*
https://leetcode.com/problems/median-of-two-sorted-arrays/

*/
class Solution {
private:
    int findKth(vector<int>& nums1,int l1,int r1,vector<int>& nums2,int l2,int r2,int k){
        if(l1>r1) return nums2[l2+k-1];
        if(l2>r2) return nums1[l1+k-1];
        int mid1=(l1+r1)/2,mid2=(l2+r2)/2;
        if(nums1[mid1]<=nums2[mid2]){
            if(k<=(mid1-l1)+(mid2-l2)+1) return findKth(nums1,l1,r1,nums2,l2,mid2-1,k);
            else return findKth(nums1,mid1+1,r1,nums2,l2,r2,k-(mid1-l1)-1);
        }
        else{
            if(k<=(mid1-l1)+(mid2-l2)+1)
                return findKth(nums1,l1,mid1-1,nums2,l2,r2,k);
            else
                return findKth(nums1,l1,r1,nums2,mid2+1,r2,k-(mid2-l2)-1);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int k=(m+n+1)/2;
        double v=(double)findKth(nums1,0,m-1,nums2,0,n-1,k);
        if((m+n)%2==0){
            int k2=k+1;
            double v2=(double)findKth(nums1,0,m-1,nums2,0,n-1,k2);
            v=(v+v2)/2;
        }
        return v;
    }
};
