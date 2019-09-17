/*
https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

*/
class Solution {
private:
    bool helper(vector<int>& nums,int target,int cur,int k,int start,vector<bool>& visited){
        if(k==0) return true;
        else if(cur>target) return false;
        else if(cur==target) return helper(nums,target,0,k-1,0,visited);
        for(int i=start;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                if(helper(nums,target,cur+nums[i],k,i+1,visited)) return true;
                visited[i]=false;
            }
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int max_num=0,sum=0;
        for(auto num:nums){
            sum+=num;
            max_num=max(max_num,num);
        }
        if(sum%k!=0||max_num>sum/k) return false;
        vector<bool> visited(nums.size(),false);
        return helper(nums,sum/k,0,k,0,visited);
    }
};
