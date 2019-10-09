/*
https://leetcode.com/problems/split-array-with-equal-sum/

*/
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if(nums.size()<7) return false;
        vector<int> sum(nums.size(),0);
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            sum[i]=sum[i-1]+nums[i];
        for(int j=3;j<nums.size()-3;j++){
            unordered_set<int> s;
            for(int i=1;i<j-1;i++){
                if(sum[i-1]==sum[j-1]-sum[i])
                    s.insert(sum[i-1]);
            }
            for(int k=j+2;k<nums.size()-1;k++){
                if(sum[nums.size()-1]-sum[k]==sum[k-1]-sum[j]&&s.count(sum[k-1]-sum[j]))
                    return true;
            }
        }
        return false;
    }
};
