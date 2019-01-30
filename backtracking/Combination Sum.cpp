/*
https://leetcode.com/problems/combination-sum/

*/
class Solution {
private:
    void backtrack(vector<vector<int>>& res,vector<int>& tmp,int sum,vector<int>& nums,int target,int start){
        if(sum>target) return;
        if(sum==target) res.push_back(tmp);
        else{
            for(int i=start;i<nums.size();i++){
                sum+=nums[i];
                tmp.push_back(nums[i]);
                backtrack(res,tmp,sum,nums,target,i);
                sum-=nums[i];
                vector<int>::iterator it=tmp.end();
                tmp.erase(it-1);
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=0;
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res,tmp,sum,candidates,target,0);
        return res;
    }
};
