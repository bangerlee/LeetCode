/*
https://leetcode.com/problems/sliding-window-maximum/

*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!q.empty()&&q.front()<i-k+1) q.pop_front();
            while(!q.empty()&&nums[i]>nums[q.back()]) q.pop_back();
            q.push_back(i);
            if(i>=k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
