/*
https://leetcode.com/problems/sliding-window-median/

*/
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> windows(nums.begin(),nums.begin()+k);
        auto mid=next(windows.begin(),k/2);
        vector<double> res;
        for(int i=k;;i++){
            res.push_back((double(*mid) + *prev(mid,1-k%2))/2);
            if(i==nums.size()) return res;
            windows.insert(nums[i]);
            if(nums[i]<*mid) mid--;
            if(nums[i-k]<=*mid) mid++;
            windows.erase(windows.lower_bound(nums[i-k]));
        }
    }
};
