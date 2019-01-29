/*
https://leetcode.com/problems/array-nesting/

*/
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            int j=i,tmp=0;
            while(nums[j]>=0){
                tmp++;
                int k=nums[j];
                nums[j]=-1;
                j=k;
            }
            res=max(res,tmp);
        }
        return res;
    }
};
