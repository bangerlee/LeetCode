/*
https://leetcode.com/problems/subarray-sum-equals-k/

prefix sum
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0,res=0;
        for(auto& a:nums){
            sum+=a;
            res+=m[sum-k];
            m[sum]++;
        }
        return res;
    }
};
