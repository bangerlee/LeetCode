/*
https://leetcode.com/problems/wiggle-sort-ii/

*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int m=nums.size();
        auto mptr=nums.begin()+(m-1)/2;
        nth_element(nums.begin(),mptr,nums.end());
        int median=*mptr;
        int i=1,j=((m-1)&1)?m-2:m-1;
        for(int l=0;l<m;l++){
            if(nums[l]>median){
                if(l<=i&&(l&1)) continue;
                swap(nums[l--],nums[i]);
                i+=2;
            }
            else if(nums[l]<median){
                if(l>=j&&(l&1)==0) continue;
                swap(nums[l--],nums[j]);
                j-=2;
            }
        }
    }
};
