/*
https://leetcode.com/problems/increasing-subsequences/

*/
class Solution {
private:
    void helper(vector<int>& nums,vector<int>& tmp,int pos,vector<vector<int>>& res){
        if(tmp.size()>1) res.push_back(tmp);
        set<int> used;
        for(int i=pos;i<nums.size();i++){
            if(used.count(nums[i])) continue;
            if(tmp.size()==0||tmp.back()<=nums[i]){
                tmp.push_back(nums[i]);
                used.insert(nums[i]);
                helper(nums,tmp,i+1,res);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(nums,tmp,0,res);
        return res;
    }
};
