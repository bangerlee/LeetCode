/*
https://leetcode.com/problems/subsets-ii/

*/
class Solution {
private:
    void backtrack(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,int start){
        res.push_back(tmp);
        for(int i=start;i<nums.size();i++){
            if(i>start&&nums[i]==nums[i-1]) continue;
            tmp.push_back(nums[i]);
            backtrack(res,tmp,nums,i+1);
            vector<int>::iterator it=tmp.end();
            tmp.erase(it-1);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res,tmp,nums,0);
        return res;
    }
};
