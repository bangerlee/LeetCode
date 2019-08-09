/*
https://leetcode.com/problems/count-of-smaller-numbers-after-self/

*/
#define iterator vector<vector<int>>::iterator
class Solution {
private:
    void sort_count(iterator l,iterator r,vector<int>& res){
        if(r-l<=1) return;
        iterator m=l+(r-l)/2;
        sort_count(l,m,res);
        sort_count(m,r,res);
        for(iterator i=l,j=m;i<m;i++){
            while(j<r && (*i)[0]>(*j)[0]) j++;
            res[(*i)[1]]+=j-m;
        }
        inplace_merge(l,m,r);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<vector<int>> hold;
        int n=nums.size();
        for(int i=0;i<n;i++) hold.push_back({nums[i],i});
        vector<int> res(n,0);
        sort_count(hold.begin(),hold.end(),res);
        return res;
    }
};
