/*
https://leetcode.com/problems/max-chunks-to-make-sorted/

*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res=0,m=0;
        for(int i=0;i<arr.size();i++){
            m=max(m,arr[i]);
            if(m==i) res++;
        }
        return res;
    }
};
