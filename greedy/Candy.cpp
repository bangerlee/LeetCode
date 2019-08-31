/*
https://leetcode.com/problems/candy/

*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int res=0,n=ratings.size();
        if(n<=1) return n;
        vector<int> v(n,1);
        for(int i=1;i<n;i++)
            if(ratings[i]>ratings[i-1]) v[i]=v[i-1]+1;
        for(int i=n-1;i>0;i--)
            if(ratings[i-1]>ratings[i]) v[i-1]=max(v[i-1],v[i]+1);
        for(auto& x:v) res+=x;
        return res;
    }
};
