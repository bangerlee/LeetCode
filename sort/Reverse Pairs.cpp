/*
https://leetcode.com/problems/reverse-pairs/

*/
class Solution {
private:
    int sort_count(vector<int>::iterator begin,vector<int>::iterator end){
        if(end-begin<=1) return 0;
        vector<int>::iterator mid=begin+(end-begin)/2;
        int res=0;
        if(begin<mid) res+=sort_count(begin,mid);
        if(mid<end) res+=sort_count(mid,end);
        vector<int>::iterator i,j;
        for(i=begin,j=mid;i<mid;i++){
            while(j<end && *i>2L**j) j++;
            res+=j-mid;
        }
        inplace_merge(begin,mid,end);
        return res;
    }
public:
    int reversePairs(vector<int>& nums) {
        return sort_count(nums.begin(),nums.end());
    }
};
