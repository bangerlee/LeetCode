/*
https://leetcode.com/problems/combination-sum-ii/

*/
class Solution {
private:
    void backtrack(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,int sum,int target,int start){
        if(sum>target) return;
        if(sum==target) {
            if(find(res.begin(),res.end(),tmp)==res.end())
                res.push_back(tmp);
        }
        else{
            for(int i=start;i<nums.size();i++){
                sum+=nums[i];
                tmp.push_back(nums[i]);
                backtrack(res,tmp,nums,sum,target,i+1);
                sum-=nums[i];
                vector<int>::iterator it=tmp.end();
                tmp.erase(it-1);
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        int sum=0;
        sort(candidates.begin(),candidates.end());
        backtrack(res,tmp,candidates,sum,target,0);
        return res;
    }
};
