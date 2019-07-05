/*
https://leetcode.com/submissions/detail/192510259/
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(),-1);
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--)
            st.push(i);
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty()&&nums[i]>=nums[st.top()])
                st.pop();
            if(!st.empty()){
                res[i]=nums[st.top()];
            }
            st.push(i);
        }
        return res;
    }
};
