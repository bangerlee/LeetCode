/*
https://leetcode.com/problems/find-the-duplicate-number/

*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=1,j=nums.size()-1;
        while(i<j){
            int mid=i+(j-i)/2,count=0;
            for(int k:nums)
                if(k<=mid) count++;
            if(count<=mid) i=mid+1;
            else j=mid;
        }
        return i;
    }
};
