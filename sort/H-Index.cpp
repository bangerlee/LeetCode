/*
https://leetcode.com/problems/h-index/

*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int max=0;
        sort(citations.begin(),citations.end());
        for(int i=citations.size()-1;i>=0;i--){
            int tmp=citations[i]>citations.size()-i?citations.size()-i:citations[i];
            if(tmp>max) max=tmp;
        }
        return max;
    }
};
