/*
https://leetcode.com/problems/3sum-closest/

*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=INT_MIN,len=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++){
            int left=i+1,right=len-1;
            while(left<right){
                int tmp=nums[i]+nums[left]+nums[right];
                if(tmp<target) left++;
                else if(tmp>target) right--;
                else return target;
                if(res==INT_MIN || abs(target-res)>abs(target-tmp)) res=tmp;
                
            }
        }
        return res;
    }
};
