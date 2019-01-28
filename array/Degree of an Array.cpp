/*
https://leetcode.com/problems/degree-of-an-array/

loop only once on array {
    record the index of first occureence;
    update number counter;
    update result;
}
return result;
*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> counter,first;
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
