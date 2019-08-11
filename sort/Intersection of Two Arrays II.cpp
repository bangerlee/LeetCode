/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/

*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> res;
        int i1=0,i2=0;
        while(i1<nums1.size()&&i2<nums2.size()){
            if(nums1[i1]==nums2[i2]){
                res.push_back(nums1[i1]);
                i1++,i2++;
            }
            else if(nums1[i1]>nums2[i2]) i2++;
            else i1++;
        }
        return res;
    }
};
