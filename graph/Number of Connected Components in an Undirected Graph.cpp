/*
https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

*/
class Solution {
private:
    int find(vector<int>& nums,int i){
        while(nums[i]!=i){
            nums[i]=nums[nums[i]];
            i=nums[i];
        }
        return i;
    }
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> nums(n,-1);
        for(int i=0;i<n;i++) nums[i]=i;
        int res=n;
        for(auto edge:edges){
            int x=find(nums,edge.first);
            int y=find(nums,edge.second);
            if(x!=y){ nums[x]=y;res--;}
        }
        return res;
    }
};
