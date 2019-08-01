/*
https://leetcode.com/problems/contains-duplicate/

*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int x:nums) if(m[x]++==1) return true;
        return false;
    }
};
