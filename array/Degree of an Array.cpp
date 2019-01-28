/*
https://leetcode.com/problems/degree-of-an-array/

*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> counter,first;
        int res=INT_MAX,degree=0;
        for(int i=0;i<nums.size();i++){
            if(first.count(nums[i])==0) first[nums[i]]=i;
            if(++counter[nums[i]]>degree){
                degree=counter[nums[i]];
                res=i-first[nums[i]]+1;
            }
            else if(counter[nums[i]]==degree)
                res=min(res,i-first[nums[i]]+1);
        }
        return res;
    }
};
