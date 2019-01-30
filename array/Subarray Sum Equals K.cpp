/*
https://leetcode.com/problems/subarray-sum-equals-k/

*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int res=0,sum=0;
        for(int x:nums){
            sum+=x;
            res+=m[sum-k];
            m[sum]++;
        }
        return res;
    }
};
