/*
https://leetcode.com/problems/two-sum/

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> res(2);
        for(int i=0;i<nums.size();i++) m[nums[i]]=i;
        for(int j=0;j<nums.size();j++){
            auto it=m.find(target-nums[j]);
            if(it!=m.end()&&it->second!=j){
                res[0]=j;
                res[1]=m[target-nums[j]];
                return res;
            }
        }
        return res;
    }
};
