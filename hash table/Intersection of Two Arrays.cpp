/*
https://leetcode.com/problems/intersection-of-two-arrays/

*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        vector<int> res;
        for(auto& a:s1)
            if(s2.count(a)) res.push_back(a);
        return res;
    }
};
