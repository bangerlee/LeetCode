/*
https://leetcode.com/problems/majority-element/

*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mask=1,size=nums.size(),len=sizeof(int)*8,ret=0;
        for(int i=0;i<len;i++){
            int count=0;
            for(int j=0;j<size;j++){
                if(nums[j]&mask) count++;
                if(count>size/2){
                    ret|=mask;
                    break;
                }
            }
            mask<<=1;
        }
        return ret;
    }
};
