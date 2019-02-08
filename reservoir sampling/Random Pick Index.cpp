/*
https://leetcode.com/problems/random-pick-index/

*/
class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums=nums;
    }
    
    int pick(int target) {
        int res=0,count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=target) continue;
            if(rand()%(++count)==0) res=i;
            }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
