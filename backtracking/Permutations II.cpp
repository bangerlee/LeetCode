class Solution {
private:
    void backtrack(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,vector<bool>& used){
        if(tmp.size()==nums.size()) res.push_back(tmp);
        else{
            for(int i=0;i<nums.size();i++){
                if(used[i]||(i>0&&nums[i]==nums[i-1]&&!used[i-1])) continue;
                tmp.push_back(nums[i]);
                used[i]=true;
                backtrack(res,tmp,nums,used);
                used[i]=false;
                vector<int>::iterator it=tmp.end();
                tmp.erase(it-1);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        backtrack(res,tmp,nums,used);
        return res;
    }
};
