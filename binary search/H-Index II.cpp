/*
https://leetcode.com/problems/h-index-ii/

Runtime: 24 ms
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i=0,j=citations.size()-1,max=0;
        if(citations.size()==0) return 0;
        if(citations.size()==1) return citations[0]==0?0:1;
        while(i<=j){
            int mid=i+(j-i)/2;
            int n=citations.size()-mid;
            if(citations[mid]>=n&&n>max){
                max=n;
            }
            if(citations[mid]<n){
                if(i==mid) i++;
                else i=mid;
            }
            else
                j=mid-1;
        }
        return max;
    }
};
