/*
https://leetcode.com/problems/number-of-valid-subarrays/
*/
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int res=0;
        stack<int> st;
        for(auto& n:nums){
            while(!st.empty()&&n<st.top()) st.pop();
            st.push(n);
            res+=st.size();
        }
        return res;
    }
};
