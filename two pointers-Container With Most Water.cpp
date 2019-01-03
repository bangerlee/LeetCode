/*
https://leetcode.com/problems/container-with-most-water/

Runtime: 20 ms
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,res=0;
        while(i<j){
            int h=min(height[i],height[j]);
            res=max(res,h*(j-i));
            while(i<j&&height[i]<=h) i++;
            while(i<j&&height[j]<=h) j--;
        }
        return res;
    }
};
