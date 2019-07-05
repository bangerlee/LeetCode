/*
https://leetcode.com/problems/largest-rectangle-in-histogram/
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> monostack;
        int res=0;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++){
            while(!monostack.empty()&&heights[monostack.top()]>heights[i]){
                int h=heights[monostack.top()];
                monostack.pop();
                
                int idx=monostack.empty()?-1:monostack.top();
                res=max(res,h*(i-idx-1));
            }
            monostack.push(i);
        }
        return res;
    }
};
