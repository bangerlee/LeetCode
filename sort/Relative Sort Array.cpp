/*
https://leetcode.com/problems/relative-sort-array/

*/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> counter(1001,0);
        for(auto k:arr1) counter[k]++;
        int i=0;
        for(auto& k:arr2)
            while(counter[k]-->0) arr1[i++]=k;
        for(int k=0;k<counter.size();k++)
            while(counter[k]-->0) arr1[i++]=k;
        return arr1;
    }
};
