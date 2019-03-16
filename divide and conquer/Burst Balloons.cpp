/*
https://leetcode.com/problems/burst-balloons

*/
class Solution {
private:
    int burst(vector<int>& v,vector<vector<int>>& memo,int left,int right){
        if(left+1>=right) return 0;
        if(memo[left][right]>0) return memo[left][right];
        int res=0;
        for(int i=left+1;i<right;i++)
            res=max(res,v[left]*v[i]*v[right]+burst(v,memo,left,i)+burst(v,memo,i,right));
        memo[left][right]=res;
        return res;
    }
public:
    int maxCoins(vector<int>& nums) {
        vector<int> v(nums.size()+2);
        int idx=1;
        for(auto num:nums) v[idx++]=num;
        v[0]=v[idx++]=1;
        vector<vector<int>> memo(idx,vector<int>(idx));
        return burst(v,memo,0,idx-1);
    }
};
