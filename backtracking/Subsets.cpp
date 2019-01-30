/*
https://leetcode.com/problems/subsets/

*/
class Solution {
private:
    void backtrack(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,int start){
        res.push_back(tmp);
        for(int i=start;i<nums.size();i++){
            tmp.push_back(nums[i]);
            backtrack(res,tmp,nums,i+1);
            vector<int>::iterator it=tmp.end();
            tmp.erase(it-1);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res,tmp,nums,0);
        return res;
    }
};
