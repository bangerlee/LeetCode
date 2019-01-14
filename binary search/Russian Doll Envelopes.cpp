/*
https://leetcode.com/problems/russian-doll-envelopes/

Runtime: 24 ms
*/
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](pair<int,int> a,pair<int,int> b){
            if(a.first==b.first) return a.second>b.second; 
            else return b.first>a.first;
        });
        
        vector<int> v(envelopes.size());
        int size=0;
        for(auto x:envelopes){
            int i=0,j=size;
            while(i<j){
                int mid=(i+j)/2;
                if(v[mid]<x.second) i=mid+1;
                else j=mid;
            }
            v[i]=x.second;
            if(i==size) size++;
        }
        return size;
    }
};
